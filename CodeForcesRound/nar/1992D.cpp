#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string a;
    cin >> a;
    vector<int> dp(n + 2, INF);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i > n || a[i - 1] != 'C') {
            for (int j = max(0, i - m); j < i; j++) {
                if (j == 0 || a[j - 1] == 'L' || i - j == 1) dp[i] = min(dp[j], dp[i]);
                // cout << j << " ";
            }
            
            if (a[i - 1] == 'W') dp[i]++;
            // cout << endl;
        }
        // cout << dp[i] << " ";
    }
    // cout << endl;
    // cout << dp[n] << endl;
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    if (dp[n + 1] == INF || dp[n + 1] > k) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}