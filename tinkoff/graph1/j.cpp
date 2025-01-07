#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[b].push_back({a, c});
    }
    vector<int> used1(n, INF);
    vector<int> used2(n, INF);
    queue<pair<int, int>> q;
    used1[n - 1] = 0;
    used2[n - 1] = 0;
    q.push({n - 1, 1});
    q.push({n - 1, 2});
    while (!q.empty()) {
        int num = q.front().F;
        int type = q.front().S;
        q.pop();
        if (type == 1) {
            for (auto &x : g[num]) {
                if (used2[x.F] == INF && x.S == 2) {
                    used2[x.F] = used1[num] + 1;
                    q.push({x.F, 2});
                }
            }
        } else {
            for (auto &x : g[num]) {
                if (used1[x.F] == INF && x.S == 1) {
                    used1[x.F] = used2[num] + 1;
                    q.push({x.F, 1});
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
        cout << ((min(used1[i], used2[i]) == INF)?-1:min(used1[i], used2[i])) << " ";
    cout << endl;
    return 0;
}