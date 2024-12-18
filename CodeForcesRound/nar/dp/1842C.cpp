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
    vector<int> l(n);
    vector<int> count(n + 1, -1);
    for (int i = 0; i < n; i++) {
        l[i] = count[a[i]];
        count[a[i]] = i;
    }
    vector<int> dp(n + 1);
    dp[1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = dp[i];
        if (l[i] != -1)
            dp[i + 1] = max(dp[i], max(dp[l[i]] + (i - l[i] + 1), dp[l[i] + 1] + (i - l[i])));
    }
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}