#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1);
    vector<int> pred(n + 1);
    dp[1] = a[0];
    for (int i = 1; i < n; i++) {
        // cout << dp[i] + a[i] << " " << dp[i - 1] + a[i - 1] - a[i] << endl;
        if (abs(dp[i] + a[i]) < abs(dp[i - 1] + a[i - 1] - a[i])) {
            dp[i + 1] = dp[i] + a[i];
            pred[i + 1] = 0;
        } else if (abs(dp[i] + a[i]) == abs(dp[i - 1] + a[i - 1] - a[i])) {
            if (a[i + 1] <= 0) {
                if (dp[i] + a[i] >= dp[i - 1] + a[i - 1] - a[i]) {
                    dp[i + 1] = dp[i] + a[i];
                    pred[i + 1] = 0;
                } else {
                    dp[i + 1] = dp[i - 1] + a[i - 1] - a[i];
                    pred[i + 1] = 1;
                }
            } else {
                if (dp[i] + a[i] <= dp[i - 1] + a[i - 1] - a[i]) {
                    dp[i + 1] = dp[i] + a[i];
                    pred[i + 1] = 0;
                } else {
                    dp[i + 1] = dp[i - 1] + a[i - 1] - a[i];
                    pred[i + 1] = 1;
                }
            }
        } else {
            dp[i + 1] = dp[i - 1] + a[i - 1] - a[i];
            pred[i + 1] = 1;
        }
    }
    if (dp[n] != 0) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ans = {};
    for (int i = n; i > 0; i--) {
        if (pred[i] == 0) ans.push_back({i, i});
        else ans.push_back({i - 1, i});
        if (pred[i] == 1) i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x.F << " " << x.S << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}