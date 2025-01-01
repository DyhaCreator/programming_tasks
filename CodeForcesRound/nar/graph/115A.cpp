#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(vector<vector<int>> &g, vector<int> &used, int col, int index) {
    used[index] = col;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, col + 1, x);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> tr(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tr[i] = a;
        a--;
        if (a >= 0) g[a].push_back(i);
    }
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        if (tr[i] == -1) {
            dfs(g, used, 1, i);
        }
    }
    int ans = 0;
    for (auto &x : used)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}