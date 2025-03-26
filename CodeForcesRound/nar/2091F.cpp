#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(m, 0));
    for (auto &x : dp[0])
        x = 0;
    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < m; i++)
        pref[0][i + 1] = pref[0][i] + dp[0][i];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (y != 0) {
                int l = 0;
                int r = x;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (1 + ((mid - x) * (mid - x)) > d * d) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                int ld = r;
                l = x;
                r = m;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (1 + ((mid - x) * (mid - x)) <= d * d) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                if (a[y][x] == 'X') {
                    dp[y + 1][x] = (pref[y][r] - pref[y][ld] + 998244353) % 998244353;
                }
            } else {
                for (int x = 0; x < m; x++) {
                    if (a[y][x] == 'X') {
                        dp[y + 1][x] = 1;
                    }
                }
            }
        }
        for (int x = 0; x < m; x++)
            pref[y + 1][x + 1] = (pref[y + 1][x] + dp[y + 1][x]) % 998244353;
        for (int x = 0; x < m; x++) {
            // cout << x << " " << x - d << " " << x + d + 1 << endl;
            if (a[y][x] == 'X') dp[y + 1][x] = (pref[y + 1][min(x + d + 1, m)] - pref[y + 1][max(x - d, 0)] + 998244353) % 998244353; 
        }
        for (int x = 0; x < m; x++)
            pref[y + 1][x + 1] = (pref[y + 1][x] + dp[y + 1][x]) % 998244353;
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : pref) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << pref[n][m] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}