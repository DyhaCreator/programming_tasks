#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<int> dp(n + 1);
    vector<int> dpost(n + 1);
    dpost[0] = p;
    for (int i = 0; i < n; i++) {
        if (dpost[i] >= a[i]) {
            dp[i + 1] = dp[i] + 1;
            dpost[i + 1] = dpost[i] - a[i];
        }
        if (i > 0 && dp[i - 1] + 2 >= dp[i] + 1 && dpost[i - 1] >= a[i]) {
            dp[i + 1] = dp[i - 1] + 2;
            dpost[i + 1] = dpost[i - 1] - a[i];
        }
        if (dp[i + 1] == 0 && p >= a[i]) {
            dp[i + 1] = 1;
            dpost[i + 1] = p - a[i];
        }
        // cout << dp[i] << " " << dpost[i] << endl;
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    /*for (int i = 0; i < n; i++) {
        cout << dp[i] << " " << dpost[i] << endl;
    }*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}