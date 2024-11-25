#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    vector<vector<int>> dp_last(n + 1, vector<int>(3));
    dp[0] = {0, 0, 0};
    dp_last[0] = {-INF, -INF, -INF};
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp_last[i][0] = a[i - 1].F;
        if (dp_last[i - 1][0] < a[i - 1].F - a[i - 1].S) {
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            dp_last[i][1] = a[i - 1].F;
        }
        if (dp_last[i - 1][1] < a[i - 1].F - a[i - 1].S) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            dp_last[i][1] = a[i - 1].F;
        }
        if (dp_last[i - 1][2] < a[i - 1].F - a[i - 1].S) {
            dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
            dp_last[i][1] = a[i - 1].F;
        }
        if (i == n || a[i - 1].F + a[i - 1].S < a[i].F) {
            dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + 1;
            dp_last[i][2] = a[i - 1].F + a[i - 1].S;
        }
    }

    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}