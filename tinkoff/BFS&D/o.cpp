#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int n;
vector<vector<pair<int, int>>> g;

void dfs(int start, vector<int> &visited, int lay) {
    if (lay == 4) return;
    visited[start] = lay;
    for (auto &[index, c] : g[start]) {
        if (visited[index] == 0) {
            dfs(index, visited, lay + 1);
        }
    }
}

int main() {
    cin >> n;
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;
    int m;
    cin >> m;

    g = vector<vector<pair<int, int>>>(n);

    // vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back({b - 1, c[a - 1]});
        g[b - 1].push_back({a - 1, c[b - 1]});
    }
    for (int j = 0; j < n; j++) {
        vector<int> visited(n);
        dfs(j, visited, 1);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 3) {
                g[j].push_back({i, c[j] * 2});
            }
        }
    }

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

        for (auto &[index, weight] : g[near]) {
            if (dist[index] > dist[near] + weight) {
                dist[index] = dist[near] + weight;
            }
        }
    }

    cout << dist[n - 1] << endl;

    /*for (auto &x : dist)
        cout << x << " ";
    cout << endl;*/
    return 0;
}