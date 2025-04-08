#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++) {
        dp[i][i] = a[i];
        for (ll j = i - 1; j >= 0; j--) {
            set<pair<ll, ll>> st1;
            for (ll k = j; k <= i; k++)
                if (dp[k][j] != -1) st1.insert({dp[k][j], k});
            /*for (auto &x : st0)
                cout << x.F << " " << x.S << "  ";
            cout << endl;
            for (auto &x : st1)
                cout << x.F << " " << x.S << "  ";
            cout << endl;*/
            vector<pair<ll, ll>> c = {};
            for (auto &x : st1)
                c.push_back(x);
            for (ll k = j; k <= i + 1; k++) {
                if (dp[i][k] == -1) continue;
                pair<ll, ll> x = {dp[i][k], k};
                ll l = 0;
                ll r = c.size();
                while (l < r) {
                    ll m = (l + r) / 2;
                    if (c[m].F < x.F) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                pair<ll, ll> y = c[r];
                if (x.F == y.F && (x.S - y.S == 1 || dp[x.S - 1][y.S + 1] != -1)) {
                    dp[i][j] = x.F + y.F + max(dp[x.S - 1][y.S + 1], 0LL);
                }
            }

            /*if (a[j] == a[i]) {
                if (i - j == 1) {
                    dp[i][j] = a[i] * 2;
                } else {
                    dp[i][j] = dp[i - 1][j + 1] + a[i] * 2;
                }
            }*/
        }
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    ll ans = -1;
    for (auto &x : dp) {
        for (auto &y : x)
            ans = max(ans, y);
    }
    cout << ans << endl;
    return 0;
}