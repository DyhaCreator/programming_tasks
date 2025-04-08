#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = min(dp[i][0], min(dp[i][1], dp[i][2])) + 1;
        if ((a[i] & 0b01) > 0) {
            dp[i + 1][1] = min(dp[i][0], dp[i][2]);
        } else {
            dp[i + 1][1] = min(dp[i][0], min(dp[i][1], dp[i][2])) + 1;
        }
        if ((a[i] & 0b10) > 0) {
            dp[i + 1][2] = min(dp[i][0], dp[i][1]);
        } else {
            dp[i + 1][2] = min(dp[i][0], min(dp[i][1], dp[i][2])) + 1;
        }
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}