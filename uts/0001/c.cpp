#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int dfs(int v, vector<vector<int>> &g, int len,
        stack<pair<int, int>> &st, vector<int> &used) {
    cout << v << endl;
    used[v] = 1;
    int f = 0;
    for (auto &x : g[v])
        if (used[x] == 0) f = 1;
    if (f == 0 && len == 3) {
        return 1;
    } else if (f == 0) {
        used[v] = 0;
        return 0;
    }
    f = 1;
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            if (len == 3) {
                st.push({v, x});
                int res = dfs(x, g, 1, st, used);
                if (res == 1) {
                    f = 0;
                    return 1;
                } else {
                    st.pop();
                }
            } else if (len < 3) {
                int res = dfs(x, g, len + 1, st, used);
                if (res == 1) {
                    f = 0;
                    return 1;
                }
            }
        }
    }
    if (f == 1) {
        used[v] = 0;
        return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> g_size(n);
    map<pair<int, int>, int> mp_index;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        g_size[a]++;
        g_size[b]++;
        mp_index[{a, b}] = i;
        mp_index[{b, a}] = i;
    }
    vector<int> ans = {};
    vector<int> used(n);
    int last_col = 0;
    int col = 0;
    do {
        last_col = col;
        col = 0;
        int root = 0;
        while (g_size[root]> 1 || used[root] == 1) root++;
        cout << root << endl;
        stack<pair<int, int>> st;
        dfs(root, g, 1, st, used);
        while (!st.empty()) {
            ans.push_back(mp_index[st.top()]);
            g_size[st.top().F]--;
            g_size[st.top().S]--;
            st.pop();
        }
        for (int i = 0; i < n; i++) {
            if (used[i] == 1) {
                for (auto &x : g[i]) {
                    if (used[x] == 0) {
                        ans.push_back(mp_index[{i, x}]);
                        g_size[i]--;
                        g_size[x]--;
                    }
                }
            }
        }
        for (auto &x : used)
            cout << x << " ";
        cout << endl;
        for (auto &x : used)
            col += x;
    } while (col - last_col > 0);
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