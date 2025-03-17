#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve(vector<ll> &dp) {
    int n;
    cin >> n;
    cout << dp[n + 1] << endl;
}

int main() {
    int len = 100010;
    vector<ll> dp(len + 1, 1);
    for (int i = 2; i <= len; i++) {
        for (int j = i + i; j <= len; j += i)
            dp[j] += dp[i];
    }
    int t;
    cin >> t;
    while (t--) solve(dp);
    return 0;
}