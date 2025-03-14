#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int col = 1;

void dfs(int v, vector<vector<int>> &g, vector<int> &used, vector<set<int>> &g2) {
    used[v] = 1;
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            g2[v].insert(x);
            dfs(x, g, used, g2);
        }
    }
}

void dfs2(int v, vector<set<int>> &g, vector<int> &s) {
    if (g[v].size() == 2 && 
        g[*g[v].begin()].size() == 0 && 
        g[*g[v].rbegin()].size() == 0) {

        s[v] = col;
        s[*g[v].begin()] = col;
        s[*g[v].rbegin()] = col;
        col++;
        return;
    }
    if (g[v].size() == 1 &&
        g[*g[v].begin()].size() == 1 && 
        g[*g[*g[v].begin()].begin()].size() == 0) {
        s[v] = col;
        s[*g[v].begin()] = col;
        s[*g[*g[v].begin()].begin()] = col;
        col++;
        return;
    }
    vector<int> del = {};
    for (auto &x : g[v]) {
        dfs2(x, g, s);
        if (s[x] != 0)
            del.push_back(x);
    }
    for (auto &x : del)
        g[v].erase(x);
        if (g[v].size() == 2 && 
        g[*g[v].begin()].size() == 0 && 
        g[*g[v].rbegin()].size() == 0) {

        s[v] = col;
        s[*g[v].begin()] = col;
        s[*g[v].rbegin()] = col;
        col++;
        return;
    }
    if (g[v].size() == 1 &&
        g[*g[v].begin()].size() == 1 && 
        g[*g[*g[v].begin()].begin()].size() == 0) {
        s[v] = col;
        s[*g[v].begin()] = col;
        s[*g[*g[v].begin()].begin()] = col;
        col++;
        return;
    }
}

void solve() {
    col = 1;
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> d;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        d.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> s(n);
    vector<int> used(n);
    vector<set<int>> g2(n);
    dfs(0, g, used, g2);
    dfs2(0, g2, s);
    for (auto &x : s) {
        if (x == 0) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans = {};
    for (int i = 0; i < n - 1; i++) {
        if (s[d[i].F] != s[d[i].S]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}