#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(vector<vector<int>> &g, vector<int> &used, int index, int col) {
    used[index] = col;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, x, col);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used(n);
    int col = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            col++;
            dfs(g, used, i, col);
        }
    }
    vector<ll> cols(col, INF);
    for (int i = 0; i < n; i++)
        cols[used[i] - 1] = min(cols[used[i] - 1], (ll)a[i]);
    ll sum = 0;
    for (auto &x : cols)
        sum += x;
    cout << sum << endl;
    return 0;
}