#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i - (x + a[i - 1] - 1) / a[i - 1] >= 0) {
            dp[i] = dp[max(i - (x + a[i - 1] - 1) / a[i - 1], 0)] + 1;
        }
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}