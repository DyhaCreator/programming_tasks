#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int ans = 0;
int n, s;
vector<vector<int >> g;

void dfs(int t, vector<int>&visited) {
    for (auto &x : g[t]) {
        if (visited[x] == 0) {
            visited[x] = 1;
            dfs(x, visited);
        }
    }
}

int main() {
    cin >> n >> s;
    s--;
    // g = vector<vector<int >> (n + 1, vector<int>(n + 1));
    g = vector<vector<int>>(n + 1, vector<int>());
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int a;
            cin >> a;
            if (a == 1) {
                g[y].push_back(x);
                // g[x].push_back(y);
            }
            // cout << g[i][j] << endl;
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (auto &x : g[i]) {
            cout << x << " ";
        }
        cout << endl;
    }*/ 
    vector<int>visited(n, 0);
    visited[s] = 1;
    dfs(s, visited);
    for (auto &x : visited) {
        // cout << x << " ";
        if (x == 1) {
            ans++;
        }
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}