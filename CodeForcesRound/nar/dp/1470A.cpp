#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(m);
    for (auto &x : b)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(2));
    vector<vector<ll>> count(n, vector<ll>(2));

    dp[0][0] = b[0];
    dp[0][1] = b[a[0] - 1];
    count[0][0] = 1;
    count[0][1] = 0;

    for (int i = 1; i < n; i++) {
        if (count[i - 1][0] == m) {
            if (count[i - 1][1] == m) {
                dp[i][0] = INF;
            } else {
                dp[i][0] = dp[i - 1][1] + b[count[i - 1][1]];
                count[i][0] = count[i - 1][1] + 1;
            }
        } else if (count[i - 1][1] == m) {
            dp[i][0] = dp[i - 1][0] + b[count[i - 1][0]];
            count[i][0] = count[i - 1][0] + 1;
        } else {
            if (dp[i - 1][0] + b[count[i - 1][0]] < dp[i - 1][1] + b[count[i - 1][1]]) {
                dp[i][0] = dp[i - 1][0] + b[count[i - 1][0]];
                count[i][0] = count[i - 1][0] + 1;
            } else if (dp[i - 1][0] + b[count[i - 1][0]] > dp[i - 1][1] + b[count[i - 1][1]]) {
                dp[i][0] = dp[i - 1][1] + b[count[i - 1][1]];
                count[i][0] = count[i - 1][1] + 1;
            } else {
                if (count[i - 1][0] < count[i - 1][1]) {
                    dp[i][0] = dp[i - 1][0] + b[count[i - 1][0]];
                    count[i][0] = count[i - 1][0] + 1;
                } else {
                    dp[i][0] = dp[i - 1][1] + b[count[i - 1][1]];
                    count[i][0] = count[i - 1][1] + 1;
                }
            }
        }
        if (dp[i - 1][0] < dp[i - 1][1]) {
            dp[i][1] = dp[i - 1][0] + b[a[i] - 1];
            count[i][1] = count[i - 1][0];
        } else if (dp[i - 1][0] > dp[i - 1][1]) {
            dp[i][1] = dp[i - 1][1] + b[a[i] - 1];
            count[i][1] = count[i - 1][1];
        } else {
            dp[i][1] = dp[i - 1][1] + b[a[i] - 1];
            count[i][1] = min(count[i - 1][0], count[i - 1][1]);
        }
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}