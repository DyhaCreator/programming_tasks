#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int >> g;

void dfs(int v, vector<int>&visited, int color) {
    for (auto &x : g[v]) {
        if (visited[x] == 0) {
            visited[x] = color;
            dfs(x, visited, color);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g = vector<vector<int >> (n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector<int>visited(n);
    int color = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = color;
            dfs(i, visited, color);
            color++;
        }
    }
    vector<vector<int >> c(color, vector<int>());
    for (int i = 0; i < n; i++) {
        c[visited[i]].push_back(i);
    }
    cout << color - 1 << endl;
    for (int i = 1; i < color; i++) {
        cout << c[i].size() << endl;
        for (auto &x : c[i]) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}