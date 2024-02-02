#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<string> g;
int n, m;

void dfs(int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;
    /*for (auto &x : visited) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    if (y > 0 && visited[y - 1][x] == 0 && g[y - 1][x] == '#') {
        dfs(y - 1, x, visited);
    }
    if (y < n - 1 && visited[y + 1][x] == 0 && g[y + 1][x] == '#') {
        dfs(y + 1, x, visited);
    }
    if (x > 0 && visited[y][x - 1] == 0 && g[y][x - 1] == '#') {
        dfs(y, x - 1, visited);
    }
    if (x < m - 1 && visited[y][x + 1] == 0 && g[y][x + 1] == '#') {
        dfs(y, x + 1, visited);
    }
}

int main() {
    cin >> n >> m;
    g = vector<string>(n);
    for (auto &x : g)
        cin >> x;
    vector<vector<int>> visited(n, vector<int>(m));
    int ans = 0;
    // dfs(0, 0, visited);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (visited[y][x] == 0 && g[y][x] == '#') {
                ans++;
                dfs(y, x, visited);
            }
        }
    }
    cout << ans << endl;
    return 0;
}