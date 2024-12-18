#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= a && dp[i] < dp[i - a] + 1 && dp[i - a] != -1)
            dp[i] = dp[i - a] + 1;
        if (i >= b && dp[i] < dp[i - b] + 1 && dp[i - b] != -1)
            dp[i] = dp[i - b] + 1;
        if (i >= c && dp[i] < dp[i - c] + 1 && dp[i - c] != -1)
            dp[i] = dp[i - c] + 1;
    }
    cout << dp[n] << endl;
    return 0;
}