#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1);
    vector<pair<int, int>> ldp(n + 1);
    ldp[0] = {INF, INF};
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + (a[i] > ldp[i].F);
        ldp[i + 1].F = a[i];
        ldp[i + 1].S = ldp[i].S;
        if (i >= 1 && dp[i + 1] > dp[i - 1] + (a[i - 1] > ldp[i - 1].S) + (a[i] > ldp[i - 1].F)) {
            dp[i + 1] = dp[i - 1] + (a[i - 1] > ldp[i - 1].S) + (a[i] > ldp[i - 1].F);
            ldp[i + 1].F = a[i];
            ldp[i + 1].S = a[i - 1];
        }
    }
    for (auto &x : dp)
        cout << x << " ";
    cout << endl;
    for (auto &x : ldp)
        cout << x.F << " ";
    cout << endl;
    for (auto &x : ldp)
        cout << x.S << " ";
    cout << endl;
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}