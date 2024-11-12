#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 3);
    dp[1] = 4;
    dp[2] = 4;
    dp[4] = 9;
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 1) {
            dp[i] = dp[i - 2] + (i / 2) * 4 + 4;
        } else {
            if (i != 4) dp[i] = dp[i - 4] + (i / 2) * 4;
        }
    }
    cout << dp[n] << endl;
    return 0;
}