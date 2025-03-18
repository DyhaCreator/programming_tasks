#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

void solve() {
    ll a, b;
    cin >> a >> b;
    vector<int> na = {};
    vector<int> nb = {};
    ll sv = a;
    while (sv > 0) {
        na.push_back(sv % 2);
        sv /= 2;
    }
    sv = b;
    while (sv > 0) {
        nb.push_back(sv % 2);
        sv /= 2;
    }
    reverse(na.begin(), na.end());
    reverse(nb.begin(), nb.end());
    /*for (auto &x : na)
        cout << x << ' ';
    cout << endl;
    for (auto &x : nb)
        cout << x << " ";
    cout << endl;*/
    int ln = 0;
    while (ln < min(na.size(), nb.size()) && na[ln] == nb[ln])
        ln++;
    // cout << ln << endl;
    ll s1 = na.size() - ln;
    ll s2 = nb.size() - ln;
    // cout << s1 << " " << s2 << endl;
    vector<vector<ll>> dp(s1 + 1, vector<ll> (s2 + 1, INF));
    dp[0][0] = 0;
    // vector<vector<vector<int>>> used(s1 + 1, vector<vector<int>> (s2 + 1, vector<int> (128)));
    if (min(s1, s2) > 0) {
        dp[1][1] = 14;
    }
    if (min(s1, s2) > 1) {
        dp[2][2] = 14;
    }
    if (min(s1, s2) > 2) {
        dp[3][3] = 14;
    }
    for (int y = 0; y <= s1; y++) {
        for (int x = 0; x <= s2; x++) {
            if (y == 0 && x == 0)
                continue;
            ll st = 1;
            while (y - st >= 0) {
                if ((dp[y - st][x] & (1LL << st)) == 0) {
                    dp[y][x] = min(dp[y][x], dp[y - st][x] + (1LL << st));
                }
                st++;
            }
            st = 1;
            while (x - st >= 0) {
                if ((dp[y][x - st] & (1LL << st)) == 0) {
                    dp[y][x] = min(dp[y][x], dp[y][x - st] + (1LL << st));
                }
                st++;
            }
        }
    }

    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << dp[s1][s2] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}