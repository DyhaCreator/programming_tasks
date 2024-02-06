#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int n, m;
vector<vector<pair<ll, ll>>> g;

vector<ll> de(int start) {
    vector<ll> dist(n, INF);
    dist[start] = 0;
    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        int nearest = -1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
                nearest = v;
            }
        }

        visited[nearest] = 1;

        for (auto &[to, weight] : g[nearest]) {
            if (dist[to] > max(dist[nearest], weight)) {
                dist[to] = max(dist[nearest], weight);
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    g = vector<vector<pair<ll, ll>>>(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1, c});
        g[b - 1].push_back({a - 1, c});
    }

    int start, finish;
    cin >> start >> finish;
    
    vector<ll> dist = de(start - 1);

    cout << dist[finish - 1] << endl;
    /*for (auto &x : dist)
        cout << x << " ";
    cout << endl;*/
    return 0;
}