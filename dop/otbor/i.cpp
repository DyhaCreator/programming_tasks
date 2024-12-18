#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n, m;
int color = 1;
int cnt = 0;

int dfs(int index, vector<vector<int>> &g, vector<vector<int>> &gr, vector<int> &visited) {
    cnt++;
    visited[index] = color;
    for (auto &x : g[index]) {
        for (auto &y : gr[x]) {
            if (visited[y] == 0) {
                dfs(y, g, gr, visited);
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(0));
    vector<vector<int>> gr(m);
    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        vector<int> a(l);
        for (auto &x : a) {
            cin >> x;x--;
        }
        gr[i] = a;
        for (auto &x : a)
            g[x].push_back(i);
    }
    vector<int> visited(n, 0);
    int first = 0;
    while (first < n) {
        dfs(first, g, gr, visited);
        color++;
        while (first < n && visited[first] != 0) {
            first++;
        }
    }
    color--;
    vector<int> ans(color, 0);
    for (auto &x : visited)
        ans[x - 1]++;
    for (auto &x : visited)
        cout << ans[x - 1] << " ";
    cout << endl;
    return 0;
}