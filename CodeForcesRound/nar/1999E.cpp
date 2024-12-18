#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int len = 2 * 1e5 + 7;

vector<int> dp(len + 1);

void solve() {
    int l, r;
    cin >> l >> r;
    ll ans = dp[l];
    for (int i = l; i <= r; i++)
        ans += dp[i];
    cout << ans << endl;
}

int main() {
    dp[0] = 0;
    for (int i = 1; i <= len; i++)
        dp[i] = dp[i / 3] + 1;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}