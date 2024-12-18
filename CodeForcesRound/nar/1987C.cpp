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
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] > last) {
            dp[i] = max(a[i - 1], dp[i - 1]);
        } else {
            dp[i] = dp[i - 1] + 1;
        }
        if (dp[i] <= dp[i - 1]) {
            dp[i]++;
        }
        last = a[i - 1];
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}