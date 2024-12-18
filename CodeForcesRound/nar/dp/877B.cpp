#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        if (a[i] == 'a') {
            dp[i][0] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] == 'a') {
                    dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                    dp[i][2] = max(dp[i][1], dp[j][2] + 1);
                } else {
                    dp[i][2] = max(dp[i][2], dp[j][1] + 1);
                }
            }
        } else {
            dp[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] == 'a') {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                } else {
                    dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                }
            }
        }
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, max(x[0], max(x[1], x[2])));
    cout << ans << endl;
    return 0;
}