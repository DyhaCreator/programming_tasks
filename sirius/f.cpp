#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k));
    for (int i = 0; i < k; i++) {
        dp[1][i] = 1;
    }
    int sum = k - 1;
    int newSum;
    for (int i = 2; i < n + 1; i++) {
        newSum = 0;
        // cout << sum << endl;
        for (int j = 0; j < k; j++) {
            dp[i][j] = sum;
            if (j != 0) {
                dp[i][j] += dp[i - 1][0];
                newSum += dp[i][j];
            }
        }
        sum = newSum;
    }

    /*for (auto &x : dp) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/

    cout << sum + dp[n][0] << endl;
    return 0;
}