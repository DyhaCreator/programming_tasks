#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int y = 0;
    while ((1 << y) < n) y++;
    vector<vector<int>> dp(y + 1, vector<int>(n));
    vector<vector<int>> dpnums(y + 1, vector<int>(n, -1));
    dpnums[0] = a;
    for (int i = 1; i <= y; i++) {
        for (int j = (1 << i) - 1; j < n; j++) {
            dpnums[i][j] = (dpnums[i - 1][j] + dpnums[i - 1][j - (1 << (i - 1))]) % 10;
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - (1 << (i - 1))];
            if (dpnums[i - 1][j] + dpnums[i - 1][j - (1 << (i - 1))] >= 10) {
                dp[i][j]++;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        y = 0;
        while ((1 << y) < r - l + 1) y++;
        cout << dp[y][r] << endl;
    }
    return 0;
}