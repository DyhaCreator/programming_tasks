#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    vector<ll> b(26);
    b[0] = 1;
    for (int i = 1; i < 26; i++) {
        b[i] = b[i - 1];
        if (i % 2 == 0) {
            b[i] *= 2;
        } else {
            b[i] *= 5;
        }
    }
    int cnt = 0;
    for (auto &x : a)
        if (x == '?') cnt++;
    vector<vector<ll>> dp(n + 1, vector<ll> (26, -INF));
    dp[n] = vector<ll>(26, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '?') {
            
        } else {
            cout << a[i] << endl;
            for (int j = 0; j < a[i] - 'A'; j++) {
                cout << 
                dp[i][a[i] - 'A'] = max(dp[i][a[i] - 'A'], dp[i + 1][j] + b[a[i] - 'A']);
            }
        }
    }
    for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}