#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<vector<int>> &g, vector<int> &used, int len) {
    used[v] = len;
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            dfs(x, g, used, len + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n - 1);
    for (auto &x : p)
        cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
        g[p[i] - 1].push_back(i + 1);
    /*for (auto &x : g) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    vector<int> used(n);
    dfs(0, g, used, 1);
    vector<int> d(n + 1);
    for (auto &x : used)
        d[x - 1]++;
    int ans = 0;
    for (auto &x : d) ans += x % 2;
    cout << ans << endl;
    return 0;
}