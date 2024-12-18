#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

vector<vector<int>> g;
int n, m;

bool bfs(int start) {
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
                if (visited[x] > 2) {
                    return false;
                }
            }
        }
    }
    /*or (auto &x : visited)
        cout << x << " ";
    cout << endl;*/
    return true;
}

int main() {
    cin >> n >> m;
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; i++) {
        if (bfs(i)) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}