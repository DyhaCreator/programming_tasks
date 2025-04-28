#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    vector<int> dp(n, -1);
    vector<int> pred(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (((dp[m] == -1)?INF:a[dp[m]]) <= a[i]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (((dp[r] == -1)?INF:a[dp[r]]) > a[i]) {
            dp[r] = i;
            pred[i] = ((r - 1 >= 0)?dp[r - 1]:-1);
        }
        for (auto &x : dp)
            cout << x << " ";
        cout << endl;
    }
    int lst = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] != -1)
            lst = i;
    }
    vector<int> num = {};
    int v = dp[lst];
    while (v != -1) {
        num.push_back(v);
        v = pred[v];
    }

    vector<int> l = {};
    vector<int> r = {};
    v = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v < num.size() && num[v] == i) {
            v++;
            l.push_back(a[i]);
        } else {
            r.push_back(a[i]);
        }
    }
    for (auto &x : l)
        cout << x << " ";
    cout << endl;
    for (auto &x : r)
        cout << x << " ";
    cout << endl;
    int ans = 0;
    for (int i = 1; i < l.size(); i++) {
        if (l[i] > l[i - 1]) {
            ans++;
        }
    }
    for (int i = 1; i < r.size(); i++) {
        if (r[i] > r[i - 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}