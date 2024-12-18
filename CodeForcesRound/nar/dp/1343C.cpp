#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> dp(n);
    dp[0] = a[0];
    int last = a[0];
    for (int i = 1; i < n; i++) {
        if ((last > 0) == (a[i] > 0)) {
            if (dp[i - 1] < dp[i - 1] - last + a[i]) {
                dp[i] = dp[i - 1] - last + a[i];
                last = a[i];
            } else {
                dp[i] = dp[i - 1];
            }
        } else {
            dp[i] = dp[i - 1] + a[i];
            last = a[i];
        }
    }
    cout << dp[n - 1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}