#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define ll long long
#define INF 2000000000000000007
using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1, c});
        g[b - 1].push_back({a - 1, c});
    }

    vector<pair<ll, ll>> dist(n, {INF, -1});
    dist[s - 1].first = 0;
    vector<int> visited(n);
    
    set<pair<ll, ll>> st;
    for (int v = 0; v < g.size(); v++) {
        st.insert({dist[v].first, v});
    }
    for (int i = 0; i < n; i++) {
        int near = st.begin()->second;
        st.erase(st.begin());
        /*for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && (near == -1 || dist[near].first > dist[v].first)) {
                near = v;
            }
        }*/

        // cout << near << endl;
        visited[near] = 1;

        for (auto &x : g[near]) {
            if (dist[x.first].first > dist[near].first + x.second) {
                st.erase({dist[x.first].first, x.first});
                dist[x.first].first = dist[near].first + x.second;
                dist[x.first].second = near;
                st.insert({dist[x.first].first, x.first});
            }
        }
        /*for (auto &x : dist) {
            cout << x.first << " ";
        }
        cout << endl;*/
    }

    if (dist[f - 1].first == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[f - 1].first << " ";
    int p = dist[f - 1].second;
    vector<int> ans = {f - 1};
    while (p != -1) {
        ans.push_back(p);
        p = dist[p].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
    return 0;
}