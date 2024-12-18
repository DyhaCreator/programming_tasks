#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

vector<vector<pair<ll, ll>>> g;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sit(n);
    for (auto &x : sit)
        cin >> x;
    g = vector<vector<pair<ll, ll>>>(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1, c});
        g[b - 1].push_back({a - 1, c});
    }

    vector<int> dist(n, INF);
    vector<int> prev(n, -1);

    for (int i = 0; i < n; i++) {
        if (sit[i] == 1) {
            dist[i] = 0;
            prev[i] = i;
        }
    }
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
                prev[to] = prev[near];
                dist[to] = dist[near] + weight;
            }
        }
    }

    /*for (auto &x : dist)
        cout << x << " ";
    cout << endl;
    for (auto &x : prev)
        cout << x << " ";
    cout << endl;*/

    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (sit[i] == 2 && (minIndex == -1 || dist[minIndex] > dist[i])) {
            minIndex = i;
        }
    }

    if (dist[minIndex] == INF || minIndex == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << prev[minIndex] + 1 << " " << minIndex + 1 << " " << dist[minIndex] << endl;
    return 0;
}