#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        a--;b--;
        g[a].push_back({b, v});
        g[b].push_back({a, v});
    }
    vector<int> used(n, INF);
    deque<int> q;
    q.push_back(s - 1);
    used[s - 1] = 0;
    while (!q.empty()) {
        int num = q.front();
        q.pop_front();
        for (auto &x : g[num]) {
            if (used[x.F] > used[num] + x.S) {
                used[x.F] = used[num] + x.S;
                if (x.S == 0) {
                    q.push_front(x.F);
                } else {
                    q.push_back(x.F);
                }
            }
        }
    }
    for (auto &x : used)
        cout << ((x >= INF)?-1:x) << " ";
    cout << endl;
    return 0;
}