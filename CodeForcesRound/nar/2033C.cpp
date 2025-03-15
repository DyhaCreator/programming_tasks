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
    vector<vector<int>> dp(2, vector<int>(n / 2 + 1));
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1]) dp[0][0]++;
    dp[1][0] = dp[0][0];
    for (int i = 0; i < n / 2; i++) {
        int ni = n - i - 1;
        int b = 0;
        if (i > 0 && a[i] == a[i - 1]) b++;
        if (i > 0 && a[ni] == a[ni + 1]) b++;
        if (a[i] == a[i + 1]) b++;
        if (a[ni] == a[ni - 1]) b++;
        int c = 0;
        swap(a[i], a[ni]);
        if (i > 0 && a[i] == a[i - 1]) c++;
        if (i > 0 && a[ni] == a[ni + 1]) c++;
        if (a[i] == a[i + 1]) c++;
        if (a[ni] == a[ni - 1]) c++;
        swap(a[i], a[ni]);
        // cout << b << " " << c << endl;
        dp[0][i + 1] = dp[0][i];
        dp[1][i + 1] = dp[0][i] - b + c;
        if (i > 0) {
            swap(a[i - 1], a[ni + 1]);
            int d = 0;
            int e = 0;
            if (i > 0 && a[i] == a[i - 1]) d++;
            if (i > 0 && a[ni] == a[ni + 1]) d++;
            if (a[i] == a[i + 1]) d++;
            if (a[ni] == a[ni - 1]) d++;
            swap(a[i], a[ni]);
            if (i > 0 && a[i] == a[i - 1]) e++;
            if (i > 0 && a[ni] == a[ni + 1]) e++;
            if (a[i] == a[i + 1]) e++;
            if (a[ni] == a[ni - 1]) e++;
            swap(a[i], a[ni]);
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i]);
            dp[1][i + 1] = min(dp[1][i + 1], dp[1][i] - d + e);
        }
    }
    int ans = INF;
    for (auto &x : dp[0])
        ans = min(ans, x);
    for (auto &x : dp[1])
        ans = min(ans, x);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}