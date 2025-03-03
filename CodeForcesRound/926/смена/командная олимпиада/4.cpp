#include <iostream>
#include <vector>

using namespace std;



int main() {
    
    int n;
    cin >> n;
    vector<vector<long long>> a(2, vector<long long> (n));
    for ( int i = 0; i < 2; i++) {
        for ( int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> dp(2, vector<long long> (n));
    int c = 1;
    dp[0][0] = a[0][0];
    for (int i = 0; i < 2; i++) {
        for (int j = c; j < n; j++) {
            dp[i][j] += a[i][j];
            if (i != 0 && j != 0) {
                dp[i][j] = dp[i][j] + max(dp[i - 1][j], dp[i][j - 1]);    
            } else {
                if (i != 0) {
                    dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        c = 0;
    }
    cout  << dp[1][n - 1];
}