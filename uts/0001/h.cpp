#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<vector<int>> &g, vector<int> &used, vector<int> &s) {
    used[v] = 1;
    if (g[v].size() == 0 && v != 0) {
        s[v] = 1;
        return;
    }
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            dfs(x, g, used, s);
            s[v] += s[x];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
    }
    vector<int> used(n);
    vector<int> s(n);
    dfs(0, g, used, s);
    sort(s.begin(), s.end());
    for (auto &x : s)
        cout << max(x, 1) << " ";
    cout << endl;
    return 0;
}