#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<set<char>> c(m);
    for (int i = 0; i < m; i++) {
        for (auto &x : a) {
            c[i].insert(x[i]);
        }
    }

    vector<vector<int>> mask(m, vector<int>(26, -1));
    for (int i = 0; i < m; i++) {
        for (auto &x : c[i]) {
            int msk = 0;
            for (int j = 0; j < n; j++)
                if (x != a[j][i]) msk += (1 << j);
            mask[i][x - 'a'] = msk;
        }
    }

    vector<vector<pair<int, char>>> dp(m + 1);
    dp[0].push_back({0, -1});
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            for (auto &x : dp[i]) {
                if (mask[i][j] != -1 && (mask[i][j] ^ x.F) == (mask[i][j] | x.F))
                    dp[i + 1].push_back({mask[i][j] | x.F, j});
            }
        }
        if (dp[i + 1].size() == 0) {
            cout << -1 << endl;
            return;
        }
    }

    /*for (auto &x : c) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : mask) {
        for (int i = 0; i < 2; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    for (auto &x : dp) {
        for (auto &y : x)
            cout << y.F << " " << int(y.S) << "  ";
        cout << endl;
    }*/
    string ans = "";
    int v = dp[m][0].F - mask[m - 1][dp[m][0].S];
    ans.push_back(dp[m][0].S + 'a');
    for (int i = m - 1; i > 0; i--) {
        for (auto &x : dp[i]) {
            if (x.F == v) {
                v -= mask[i - 1][x.S];
                ans.push_back(x.S + 'a');
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}