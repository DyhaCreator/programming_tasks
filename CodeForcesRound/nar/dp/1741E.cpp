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
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 0 && i - a[i - 1] - 1 >= 0)
            dp[i] = dp[i - a[i - 1] - 1];
        if (dp[i - 1] == 1 && i + a[i - 1] <= n) {
            dp[i + a[i - 1]] = 1;
        }
    }
    if (dp[n]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}