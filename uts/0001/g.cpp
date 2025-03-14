#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<vector<int>> &g, vector<int> &used, int col) {
    used[v] = col;
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            dfs(x, g, used, col);
        }
    }
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> g1(n);
    vector<vector<int>> g2(n);
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        a--,b--;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
    vector<int> used1(n);
    vector<int> used2(n);
    int col = 0;
    for (int i = 0; i < n; i++) {
        if (used1[i] == 0) {
            col++;
            dfs(i, g1, used1, col);
        }
    }
    col = 0;
    for (int i = 0; i < n; i++) {
        if (used2[i] == 0) {
            col++;
            dfs(i, g2, used2, col);
        }
    }
    vector<pair<int, int>> ans = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (used1[i] != used1[j] && used2[i] != used2[j]) {
                ans.push_back({i, j});
                int a = used1[i];
                int b = used1[j];
                for (int k = 0; k < n; k++) {
                    if (used1[k] == b)
                        used1[k] = a;
                }
                a = used2[i];
                b = used2[j];
                for (int k = 0; k < n; k++) {
                    if (used2[k] == b)
                        used2[k] = a;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x.F + 1 << " " << x.S + 1 << endl;
    return 0;
}