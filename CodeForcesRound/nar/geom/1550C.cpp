#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = n;
    vector<vector<bool>> dp(n, vector<bool>(n + 1, 0));
    dp[0] = vector<bool>(n + 1, 1);
    for (int i = 0; i < n; i++) {
        int l = INF;
        int r = -INF;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] >= a[i] && l > a[j] && r < a[i] && dp[i - j - 1][i + 1] == 1 && dp[i - j - 1][i] == 1) {
                dp[i - j][i + 1] = 1;
                ans++;
            } else if (a[j] < a[i] && r < a[j] && l > a[i] && dp[i - j - 1][i + 1] == 1 && dp[i - j - 1][i] == 1) {
                dp[i - j][i + 1] = 1;
                ans++;
            } else {
                break;
            }
            // cout << a[j] << " " << l << " " << r << " " << ans << endl;
            if (a[j] >= a[i]) l = min(l, a[j]);
            else r = max(r, a[j]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}