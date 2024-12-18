#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m;
vector<vector<int>> g;

void dfs(int t, vector<int> &visited, int color) {
    for (auto &x : g[t]) {
        if (visited[x] == 0) {
            visited[x] = color + 1;
            dfs(x, visited, color + 1);
        } else if (visited[x] != color - 1 && (color - visited[x] + 1) % 2 == 1) {
            cout << "NO\n";
            exit(0);
        }
    }
}

int main() {
    cin >> n >> m;
    g = vector<vector<int>> (n, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int>visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs(i, visited, 1);
        }
    }
    cout << "YES\n";
    return 0;
}