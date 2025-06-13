#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    vector<int> p = {};
    for (auto &x : a[0])
        p.push_back(x);
    for (int i = 1; i < n; i++)
        p.push_back(a[i][n - 1]);
    vector<int> cnt(2 * n + 1);
    for (auto &x : p)
        cnt[x]++;
    for (int i = 1; i <= 2 * n; i++) {
        if (cnt[i] == 0) {
            cout << i << " ";
            for (auto &x : p)
                cout << x << " ";
            cout << endl;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}