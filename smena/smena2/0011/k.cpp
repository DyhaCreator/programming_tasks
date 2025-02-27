#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int col = 0;

void dfs(vector<vector<int>> &g, vector<int> &used, int index) {
    used[index] = col;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, x);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used(n);
    for (int i = 0; i < n; i++ ) {
        if (used[i] == 0) {
            col++;
            dfs(g, used, i);
        }
    }
    vector<pair<int, int>> c(col, {-1, -1});
    for (int i = 0; i < n; i++) {
        if (c[used[i] - 1].F == -1) {
            c[used[i] - 1] = {i, i};
        } else {
            c[used[i] - 1].S = i;
        }
    }
    int ans = 0;
    int mx_r = c[0].S;
    for (int i = 1; i < col; i++) {
        if (c[i].F < mx_r)
            ans++;
        mx_r = max(mx_r, c[i].S);
    }
    cout << ans << endl;
    return 0;
}