#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> dp(n);
    dp[0] = ((s[0] - '0') % 4 == 0);
    for (int i = 1; i < n; i++) {
        if ((s[i] - '0' + (s[i - 1] - '0') * 10) % 4 == 0) {
            dp[i] = i;
        }
        dp[i] += ((s[i] - '0') % 4 == 0);
    }
    ll ans = 0;
    for (auto &x : dp)
        ans += x;
    cout << ans << endl;
    return 0;
}