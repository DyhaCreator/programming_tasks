#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> dp(n);
    vector<ll> dpcol(n);
    dpcol[0] = 1;
    for (int i = 1; i < n; i++) {
        dpcol[i] = dpcol[i - 1] + 1;
        if (s[i] != s[i - 1]) dpcol[i] = 1;
        dp[i] = dp[i - 1] + (s[i] == s[i - 1]);
    }
    ll ans = 1;
    for (int i = 1; i <= dp[n - 1]; i++) ans = (ans * i) % 998244353;
    dpcol.push_back(1);
    for (int i = 1; i <= n; i++) 
        if (dpcol[i] == 1) ans = (ans * dpcol[i - 1]) % 998244353;
    cout << dp[n - 1] << " " << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}