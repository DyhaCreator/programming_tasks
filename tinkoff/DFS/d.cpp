#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int >> g;

void dfs(int t, vector<int>&visited, int num) {
    /*for (auto &x : visited) {
        cout << x << " ";
    }
    cout << endl;*/
    for (auto &x : g[t]) {
        if (visited[x] < num && visited[x] > 0) {
            cout << "NO\n";
        exit(0);
        }
        if (visited[x] == 0) {
            visited[x] = 1;
            dfs(x, visited, num + 1);
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
        // cout << b - 1 << endl;
    }
    /*cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " ";
        for (auto &x : g[i]) {
            cout << x << " ";
        }
        cout << endl;
    }*/
    vector<int>visited(n);
    visited[0] = 1;
    dfs(0, visited, 1);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}