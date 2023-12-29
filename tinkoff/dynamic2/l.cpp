#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(k));
    dp[1] = vector<int>(k, 1);
    for (int y = 2; y < n + 1; y++) {
        for (int x = 0; x < k; x++) {
            for (int i = 0; i < k; i++) {
                if (i != x) {
                    dp[y][x] += dp[y - 1][i];
                }
            }
            //cout << dp[y][x] << " ";
        }
        //cout << endl;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += dp[n][i];
    }
    cout << ans << endl;
    return 0;
}