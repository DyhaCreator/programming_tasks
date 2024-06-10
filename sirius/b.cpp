#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n - 1] << endl;
    return 0;
}