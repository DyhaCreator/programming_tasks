#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int col = 1;

void solve() {
    int n;
    cin >> n;
    vector<set<int>> g(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].insert(b);
        g[b].insert(a);
        mp[{a, b}] = i;
        mp[{b, a}] = i;
    }
    if (n % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ans = {};
    vector<int> used(n);
    for (int i = 0; i < n / 3; i++) {
        int root = 0;
        while (root < n && (used[root] != 0 || 
        g[root].size() != 1 || g[*g[root].begin()].size() != 2)) {
            cout << root << " " << g[root].size() << " " << g[*g[root].begin()].size() << endl;
            root++;
        }
        if (root == n) {
            cout << -1 << endl;·
            return;
        }
        cout << root << endl;
        used[root] = 1;
        for (auto &x : g[root]) {
            used[x] = 1;
            for (auto &y : g[x])
                used[y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (auto &x : g[i]) {
                if (used[i] == 1 && used[x] == 0) {
                    ans.push_back({i, x});
                    g[i].erase(x);
                } else if (used[i] == 0 && used[x] == 1) {
                    g[i].erase(x);
                }
            }
        }
        for (auto &x : used)
            cout << x << " ";
        cout << endl;
    }
    for (auto &x : ans)
        cout << mp[x] + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}