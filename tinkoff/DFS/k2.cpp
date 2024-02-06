#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>>  g;
int n;

void dfs(int start, vector<int> &visited) {
    visited[start] = 1;

    for (auto &x : g[start]) {
        if (visited[x] == 0) {
            dfs(x, visited);
        }
    }
}

int main() {
    cin >> n;
    g = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        g[a - 1].push_back(i);
        g[i].push_back(a - 1);
    }
    
    vector<int> visited(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            ans++;
            dfs(i, visited);
        }
    }

    cout << ans << endl;

    return 0;
}