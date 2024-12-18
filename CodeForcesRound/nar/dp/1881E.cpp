#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) {
            dp[i + 1] = min(dp[i] + 1, dp[i - a[i]]);
        } else {
            dp[i + 1] = dp[i] + 1;
        }
    }
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}