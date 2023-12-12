#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int>dp = vector<int>(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if ((i >= a && dp[i - a] == 1) || (i >= b && dp[i - b] == 1) || (i >= c && dp[i - c] == 1)) {
            dp[i] = 1;
        }
    }
    int ans = 0;
    for (auto x : dp)
        ans += x;
    cout << ans - dp[n] << endl;
    return 0;
}