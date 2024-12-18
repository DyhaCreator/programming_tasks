#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int color = 0;

int dfs(int index, vector<vector<int>> &g, vector<int> &used) {
    used[index] = color;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(x, g, used);
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        vector<int> a(t);
        for (auto &x : a) {cin >> x;x--;}
        for (int j = 1; j < t; j++) {
            g[a[0]].push_back(a[j]);
            g[a[j]].push_back(a[0]);
        }
    }
    /*for (auto &x : g) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }*/
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            color++;
            dfs(i, g, used);
        }
    }
    vector<int> count(color, 0);
    for (auto &x : used)
        count[x - 1]++;

    for (auto &x : used)
        cout << count[x - 1] << " ";
    cout << endl;
    return 0;
}