#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1, 1);
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        int y = 2;
        while (i * y <= n) {
            if (a[i - 1] < a[i * y - 1]) dp[i * y] = max(dp[i * y], dp[i] + 1);
            y++;
        }
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
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