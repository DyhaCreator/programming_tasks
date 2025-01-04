#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    ll s;
    cin >> s;
    vector<vector<ll>> sums((1 << n), vector<ll>(m));
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) == 0) {
                    sums[i][j] += a[k][j];
                }
            }
        }
        vector<vector<ll>> dp(m + 1, vector<ll>(m + 1));
        vector<vector<ll>> pref(m + 1, vector<ll> (m + 1));
        for (int j = 1; j <= m; j++) {
            for (int k = j; k <= m; k++) {
                for (int l = j - 1; l < k; l++) {
                    if (abs(dp[j][k] - s) > abs(dp[j - 1][l] + sums[i][k - 1] - s) || dp[j][k] == 0) {
                        dp[j][k] = dp[j - 1][l] + sums[i][k - 1];
                        pref[j][k] = l;
                    }
                }
                if (dp[j][k] == s) {
                    vector<int> ans(m, 0);
                    int index = k;
                    int index2 = j;
                    while (index != 0) {
                        ans[index - 1] = 1;
                        index = pref[index2][index];
                        index2--;
                    }
                    cout << "YES" << endl;
                    int ans_num = 0;
                    for (auto &x : ans)
                        ans_num += 1 - x;
                    for (int l = 0; l < n; l++)
                        if ((i & (1 << l)) != 0) ans_num++;
                    cout << ans_num << endl;
                    for (int l = 0; l < m; l++) {
                        if (ans[l] == 0) {
                            cout << 2 << " " << l + 1 << endl;
                        }
                    }
                    for (int l = 0; l < n; l++)
                        if ((i & (1 << l)) != 0) cout << 1 << " " << l + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}