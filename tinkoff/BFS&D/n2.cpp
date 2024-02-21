#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, pair<ll, ll>>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a - 1].push_back({b - 1, {c, d}});
        g[b - 1].push_back({a - 1, {c, d}});
    }

    int l = 0;
    int r = 10000000;
    while (l < r - 1) {
        int m = (l + r) / 2;
        int weight = 3000000 + m * 100;

        // cout << m << " " << weight << endl;

        vector<int> dist(n, INF);
        dist[0] = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            int near = -1;
            for (int v = 0; v < n; v++) {
                if (visited[v] == 0 && (near == -1 || dist[v] < dist[near])) {
                    near = v;
                }
            }

            visited[near] = 1;

            for (auto &x : g[near]) {
                if (x.second.second >= weight) {
                    if (dist[x.first] > dist[near] + x.second.first) {
                        dist[x.first] = dist[near] + x.second.first;
                    }
                }
            }
        }
        //cout << dist[n - 1] << endl;
        if (dist[n - 1] < 1440) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}