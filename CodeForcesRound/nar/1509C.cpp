#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<vector<pair<ll, ll>>> mm(n, vector<pair<ll, ll>>(n));
    for (int l = 0; l < n; l++) {
        ll mn = a[l];
        ll mx = a[l];
        for (int r = l; r < n; r++) {
            mn = min(mn, a[r]);
            mx = max(mx, a[r]);
            mm[l][r] = {mn, mx};
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int r = 1; r < n; r++) {
        for (int l = r - 1; l >= 0; l--) {
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + mm[l][r].S - mm[l][r].F;
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}