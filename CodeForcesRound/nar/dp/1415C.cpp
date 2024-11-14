#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    string a;
    cin >> a;
    int X, Y;
    cin >> X >> Y;
    vector<int> dp(n + k + 1);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + k];
        if (a[i] == '0') dp[i]++;
    }
    p--;
    int ans = dp[p] * X;
    for (int start = 0; start < n - p; start++) {
        ans = min(ans, dp[start + p] * X + start * Y);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}