#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>>gr;

void dfs(int t, vector<int>&visited) {
    visited[t]= 1;
    /*for (auto &x : visited)
        cout << x << " ";
    cout << endl;*/
    for (auto &x : gr[t]) {
        if (visited[x] == 0) {
            dfs(x, visited);
        } else if (visited[x] == 2) {
            cout << "NO\n";
            exit(0);
        }
    }
    visited[t] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    gr = vector<vector<int>>(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gr[a - 1].push_back(b - 1);
    }
    vector<int>visited(n);
    visited[0] = 1;
    dfs(0, visited);
    for (auto &x : visited) {
        if (x == 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}