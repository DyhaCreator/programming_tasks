#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(n, vector<int>(h, -1));
    dp[0][a[0]] = (a[0] >= l && a[0] <= r);
    dp[0][a[0] - 1] = (a[0] - 1 >= l && a[0] - 1 <= r);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < h; j++) {
            if (dp[i][j] != -1) {
                int nl = (j + a[i + 1]) % h;
                int nr = (j + a[i + 1] - 1) % h;
                dp[i + 1][nl] = max(dp[i + 1][nl], dp[i][j] + (nl >= l && nl <= r));
                dp[i + 1][nr] = max(dp[i + 1][nr], dp[i][j] + (nr >= l && nr <= r));
            }
        }
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    int ans = 0;
    for (auto &x : dp[n - 1])
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}