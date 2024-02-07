#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

vector<vector<pair<ll, ll>>> g;
int n, s, f;

vector<ll> d(int start) {
    vector<ll> dist(n, INF);
    dist[start] = 0;
    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        int near = -1;
        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && (near == -1 || dist[near] > dist[v])) {
                near = v;
            }
        }

        visited[near] = 1;

        for (auto &[to, weight] : g[near]) {
            if (dist[to] > dist[near] + weight) {
                dist[to] = dist[near] + weight;
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> s >> f;
    g = vector<vector<pair<ll, ll>>>(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a != -1) {
                g[i].push_back({j, a});
            }
        }
    }

    vector<ll> dist = d(s - 1);

    if (dist[f - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[f - 1] << endl;
    }
    return 0;
}