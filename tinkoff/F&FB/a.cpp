#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a > -1) {
                g[i].push_back({j, a});
            }
        }
    }

    int ans = -1;

    for (int start = 0; start < n; start++) {
        vector<int> dist(n, INF);
        dist[start] = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            int near = -1;
            for (int v = 0; v < n; v++) {
                if (visited[v] == 0 && (near == -1 || dist[v] < dist[near])) {
                    near = v;
                }
            }
            
            visited[near] = 1;

            for (auto &[index, weight] : g[near]) {
                if (dist[index] > dist[near] + weight) {
                    dist[index] = dist[near] + weight;
                }
            }
        }

        for (auto &x : dist)
        if (x != INF) ans = std::max(ans, x);
    }
    cout << ans << endl;
    return 0;
}