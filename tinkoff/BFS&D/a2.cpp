#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

int n, m, s;
vector<vector<int>> g;

vector<int> bfs(int start) {
    vector<int> visited(n, INF);
    visited[start] = 0;
    vector<vector<int>> q(n);
    q[0].push_back(start);

    for (int i = 0; i < n; i++) {
        for (auto &v : q[i]) {
            for (auto &x : g[v]) {
                if (visited[x] > visited[v] + 1) {
                    visited[x] = visited[v] + 1;
                    q[visited[x]].push_back(x);
                }
            }
        }
    }
    return visited;
}

int main() {
    cin >> n >> m >> s;
    g = vector<vector<int>>(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector<int> visited = bfs(s - 1);

    for (auto &x : visited)
        if (x == INF) {
            cout << -1 << " ";
        } else {
            cout << x << " ";
        }
        // cout << x << " ";
    cout << endl;

    return 0;
}