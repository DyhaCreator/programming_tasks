#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

void dfs(int t, vector<int> &visited, int color) {
    visited[t] = 1;
    for (auto &x : g[t]) {
        if (visited[x] == 0) {
            dfs(x, visited, color + 1); 
        } else if (visited[x] == 1) {
            cout << 1 << endl;
            exit(0);
        }
    }
    visited[t] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    g = vector<vector<int>> (n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    vector<int>visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, visited, 1);
        }
    }
    // dfs(0, visited);
    cout << 0 << endl;
    return 0;
}