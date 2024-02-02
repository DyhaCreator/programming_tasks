#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;
int n, m;

void dfs(int num, vector<int> &visited, int step) {
    visited[num] = step;
    for (auto &x : g[num]) {
        if (visited[x] == 0) {
            dfs(x, visited, step + 1);
        }
        if (visited[x] > step + 1) {
            dfs(x, visited, step + 1);
        }
    }
}

bool f(vector<int> &v) {
    for (auto &x : v) {
        if (x > 3) {
            return false;
        }
    }
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
    vector<int>visited(n);
    for (int i = 0; i < n; i++) {
        visited = vector<int>(n, 0);
        dfs(i, visited, 1);
        if (f(visited)) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}