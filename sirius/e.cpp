#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        if ((i + 1) % 2 == 0 && dp[i] > dp[i / 2]) {
            dp[i] = dp[i / 2];
        }
        if ((i + 1) % 3 == 0 && dp[i] > dp[i / 3]) {
            dp[i] = dp[i / 3];
        }
        dp[i]++;
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n - 1] << endl;
    return 0;
}