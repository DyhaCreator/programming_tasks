#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n + 3, vector<ll>(4));
    dp[0] = {0, 0, 0, 0};
    dp[1] = {1, 1, 0, 0};
    dp[2] = {1, 1, 1, 1};
    for (int i = 3; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][3];
        dp[i][3] = dp[i - 1][1];
        /*for (auto &x : dp[i])
            cout << x << " ";
        cout << endl;*/
    }
    ll sum = 0;
    for (auto &x : dp[n])
        sum += x;
    cout << sum << endl;
    return 0;
}