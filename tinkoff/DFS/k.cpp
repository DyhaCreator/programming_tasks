#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

void dfs(int start, vector<int> &visited) {
    visited[start] = 1;
    /*for (auto &x : visited)
        cout << x << " ";
    cout << endl;*/
    for (auto &x : g[start]) {
        if (visited[x] == 0) {
            dfs(x, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    vector<int>visited(n);
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