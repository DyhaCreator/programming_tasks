#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

void dfs(int t, vector<int> &visited, int color) {
    visited[t] = color;
    for (auto &x : visited) {
        cout << x << " ";
    }
    cout << endl;
    for (auto &x : g[t]) {
        if (visited[x] == 0) {
            dfs(x, visited, color + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g =  vector<vector<int>> (n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> visited(n);

    dfs(0, visited, 1);

    return 0;
}