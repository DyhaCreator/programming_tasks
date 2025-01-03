#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int f = 0;

void dfs(vector<pair<int, int>> &a, vector<vector<int>> &g, vector<int> &used, int index, int len) {
    used[index] = len;
    for (auto &x : g[a[index].F - 1]) {
        if (used[x] == 0) {
            dfs(a, g, used, x, len + 1);
        } else if ((used[x] - used[index]) % 2 == 0 && (used[x] - used[index]) >= 2) {
            f = 1;
        }
    }
    for (auto &x : g[a[index].S - 1]) {
        if (used[x] == 0) {
            dfs(a, g, used, x, len + 1);
        } else if ((used[x] - used[index]) % 2 == 0 && (used[x] - used[index]) >= 2) {
            f = 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    f = 0;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    vector<int> count(n);
    for (int i = 0; i < n; i++) {
        int l = a[i].F;
        int b = a[i].S;
        count[l - 1]++;
        count[b - 1]++;
        if (l == b) f = 1;
    }
    if (f) {
        cout << "NO" << endl;
        return;
    }
    for (auto &x : count) {
        if (x != 2) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[a[i].F - 1].push_back(i);
        g[a[i].S - 1].push_back(i);
    }
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            f = 0;
            dfs(a, g, used, i, 1);
            if (f) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}