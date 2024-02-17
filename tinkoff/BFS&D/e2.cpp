#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int n, m, s, f;
vector<vector<pair<ll, ll>>> g;

int main() {
    cin >> n >> m >> s >> f;
    g = vector<vector<pair<ll, ll>>>(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1, c});
    }

    vector<pair<ll, ll>> dist(n, {INF, -1});
    dist[s - 1].first = 0;
    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        int near = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (near == -1 || dist[near].first > dist[v].first)) {
                near = v;
            }
        }

        visited[near] = 1;
        for (auto &[to, weight] : g[near]) {
            if (dist[to].first > dist[near].first + weight) {
                dist[to].first = dist[near].first + weight;
                dist[to].second = near;
            }
        }
    }

    // cout << dist[f - 1].first << endl;
    if (dist[f - 1].first == INF) {
        cout << -1 << endl;
        return 0;
    }
    //cout << dist[f - 1].first << " ";

    vector<int> ans = {};
    int p = f - 1;
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