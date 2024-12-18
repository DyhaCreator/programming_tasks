#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(n - 1);
    for (int i = 0; i < n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
    reverse(b.begin(), b.end());
    vector<ll> dp(n - 1);
    for (int i = 0; i < n - 1; i++) {
        dp[i] = b[i];
        if (i > 0) dp[i] = max(dp[i], b[i] - dp[i - 1]);
        if (i > 1) dp[i] = max(dp[i], b[i] - b[i - 1] + dp[i - 2]);
    }
    ll ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}