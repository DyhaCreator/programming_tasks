#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> dp(2, vector<ll>(n));
    ll mx0 = -INF;
    ll mx1 = -INF;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            dp[0][i] = max(mx0 + a[i], a[i]);
            dp[1][i] = mx1 + a[i];
        } else {
            dp[0][i] = mx1 + a[i];
            dp[1][i] = max(mx0 + a[i], a[i]);
        }
        mx0 = max(mx0, dp[0][i]);
        mx1 = max(mx1, dp[1][i]);
    }
    ll ans = -INF;
    for (auto &x : dp[1])
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}