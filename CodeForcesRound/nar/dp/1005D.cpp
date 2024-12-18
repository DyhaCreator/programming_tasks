#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        int sum = a[i] - '0';
        dp[i + 1] = dp[i] + (sum % 3 == 0);
        if (i > 0) {
            sum += a[i - 1] - '0';
            dp[i + 1] = max(dp[i + 1], dp[i - 1] + (sum % 3 == 0));
        }
        if (i > 1) {
            sum += a[i - 2] - '0';
            dp[i + 1] = max(dp[i + 1], dp[i - 2] + (sum % 3 == 0));
        }
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}