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
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int y = 0; y < n; y++) {
        for (int x = y - 1; x >= 0; x--) {
            dp[y][x] = INF;
            if (a[y] == a[x])
                dp[y][x] = dp[y - 1][x + 1];
            for (int i = 0; i < y - x; i++) {
                dp[y][x] = min(dp[y][x], dp[x + i][x] + dp[y][x + i + 1]);
            }
        }
    }
    for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << dp[n - 1][0] << endl;
    return 0;
}