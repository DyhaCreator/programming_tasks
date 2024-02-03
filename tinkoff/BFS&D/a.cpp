#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF -1
using namespace std;

int n, m, s;
vector<vector<int>> g;

vector<int> bfs(int start) {
    int step = 0;
    vector<int> visited(n, INF);
    queue<int> q;

    q.push(start);
    visited[start] = step;

    while (!q.empty()) {
        int index = q.front();
        // cout << index << endl;
        q.pop();
        for (auto &x : g[index]) {
            if (visited[x] == INF) {
                q.push(x);
                visited[x] = visited[index] + 1;
            }
        }
    }

    return visited;
}

int main() {
    cin >> n >> m >> s;
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> visited = bfs(s - 1);
    for (auto &x : visited)
        cout << x << " ";
    cout << endl;
    return 0;
}