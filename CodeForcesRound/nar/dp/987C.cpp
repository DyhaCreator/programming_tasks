#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e16 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(2, INF));
    for (int i = 0; i < n; i++) {
        ll mn = INF;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && mn > c[j])
                mn = c[j];
        }
        dp[i][0] = mn + c[i];
        mn = INF;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && mn > dp[j][0])
                mn = dp[j][0];
        }
        dp[i][1] = mn + c[i];
    }
    ll ans = INF;
    for (auto &x : dp)
        ans = min(ans, x[1]);
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}