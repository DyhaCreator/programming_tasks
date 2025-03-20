#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<int> &used, vector<set<int>> &g, vector<set<int>> &ng) {
    used[v] = 1;
    for (auto &x : g) {
        if (used[x] == 0) {
            dfs(x, used, g, ng);
        }
    }
    vector<int> s = {};
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n); 
    vector<set<int>> ng(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].insert(b);
        ng[b].insert(a);
    }
    vector<int> used(n);
    dfs(0, used, g, ng);

    return 0;
}