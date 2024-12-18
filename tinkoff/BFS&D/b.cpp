#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

vector<vector<int>> g;

void bfs(int start) {
    int step = 0;
    vector<int> visited(n, INF);
    queue<int> q;

    q.push(start);
    visited[start] = step;

    while (!q.empty()) {
        int index = q.front();
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
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
    }
    return 0;
}