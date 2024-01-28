#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m;
vector<vector<int>> g;

void dfs(int v, vector<int> &visited) {
    for (auto &x : g[v]) {
        if (visited[x] == 0) {
            visited[x] = 1;
            dfs(x, visited);
        }
    }
}

int main() {
    cin >> n >> m;

    if (m == n - 1) {
        g = vector<vector<int>> (n, vector<int>());
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        vector<int>visited(n);
        visited[0] = 1;
        dfs(0, visited);
        for (auto &x : visited) {
            // cout << x << " ";
            if (x == 0) {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        // cout << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}