#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
    }
    int k;
    cin >> k;
    vector<vector<pair<int, int>>> qw(n);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        qw[a].push_back({b, i});
    }
    /*for (auto &x : q) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    vector<int> ans(k);
    for (int s = 0; s < n; s++) {
        if (qw[s].size() > 0) {
            vector<int> used(n, INF);
            deque<int> q;
            used[s] = 0;
            q.push_back(s);
            while (!q.empty()) {
                int num = q.front();
                q.pop_front();
                // cout << num << endl;
                for (auto &x : g[num]) {
                    // cout << x.first << " " << used[x.first] << " " << used[num] + x.second << endl;
                    if (used[x.first] > used[num] + x.second) {
                        used[x.first] = used[num] + x.second;
                        if (x.second == 1) {
                            q.push_back(x.first);
                        } else {
                            q.push_front(x.first);
                        }
                    }
                }
            }
            for (auto &x : qw[s]) {
                if (used[x.first] == INF) ans[x.second] = -1;
                else ans[x.second] = used[x.first];
            }
        }
    }
    for (auto &x : ans)
        cout << x << endl;
    return 0;
}