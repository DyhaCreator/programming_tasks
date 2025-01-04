#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(vector<vector<int>> &g, vector<int> &used, int index, int len) {
    used[index] = len;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, x, len + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;x--;}
    vector<int> used(n);
    dfs(g, used, 0, 1);
    for (int i = 1; i < n; i++) {
        if (used[a[i - 1]] > used[a[i]]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    int mx = 0;
    for (auto &x : used)
        mx = max(mx, x);
    vector<vector<int>> cnt(mx);
    for (int i = 0; i < n; i++)
        cnt[used[a[i]] - 1].push_back(a[i]);
    for (int i = 0; i < mx; i++) {
        int l = 0;
        int r = 0;
        for (int j = 0; j < cnt[i].size(); j++) {
            vector<int> bb = {};
            for (auto &x : g[cnt[i][j]]) {
                if (used[x] == i + 2) {
                    bb.push_back(x);
                }
            }
            r += bb.size();
            vector<int> cc = {};
            for (int k = l; k < r; k++)
                cc.push_back(cnt[i + 1][k]);

            sort(bb.begin(), bb.end());
            sort(cc.begin(), cc.end());
            if (bb != cc) {
                cout << "NO" << endl;
                return 0;
            }
            l = r;
        }
    }
    cout << "YES" << endl;
    return 0;
}