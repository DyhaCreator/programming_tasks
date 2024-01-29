#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

void dfs(int t, vector<int> &visited, int color) {
    visited[t] = color;
    /*for (auto &x : visited) {
        cout << x << " ";
    }
    cout << endl;*/
    for (auto &x : g[t]) {
        if (visited[x] == 0) {
            dfs(x, visited, color + 1);
        }
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    s--;
    g = vector<vector<int>> (n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        // cout << a << " " << b << endl;
    }
    vector<int>visited(n);
    dfs(s, visited, 1);
    int mmm = 0;
    for (auto &x : visited) {
        if (x > mmm) {
            mmm = x;
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == mmm) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}