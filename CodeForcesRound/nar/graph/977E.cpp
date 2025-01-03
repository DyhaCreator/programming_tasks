#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using l = long long;

const int INF = 1e9 + 7;
int f = 0;

void dfs(vector<vector<int>> &g, vector<int> &used, map<int, int> &mp, set<int> &st, int index, int l) {
    used[index] = 1;
    st.insert(l);
    mp[l]++;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, mp, st, x, l + 1);
        }
    }
    if (g[index].size() != 2) f = 1;
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            map<int, int> mp;
            set<int> st;
            f = 0;
            dfs(g, used, mp, st, i, 1);
            int find = 1;
            for (auto &x : st)
                if (mp[x] > 1) find = 0;
            if (f == 0 && find == 1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}