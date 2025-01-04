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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[i].push_back(a[i] - 1);
        g[a[i] - 1].push_back(i);
    }
    vector<int> used(n);
    int col = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            col++;
            dfs(g, used, i, col);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[a[i] - 1] - 1 == i) {
            cnt++;
        }
    }
    if (cnt != 0) cnt -= 2;
    cout << col - cnt / 2 << " " << col << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}