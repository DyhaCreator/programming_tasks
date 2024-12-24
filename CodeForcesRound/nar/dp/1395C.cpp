#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j] = a[i] & b[j];
            int ans = INF;
            for (int k = 0; k < m; k++)
                ans = min(ans, dp[i + 1][j] | dp[i][k]);
            dp[i + 1][j] = ans;
        }
    }
    for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    int ans = INF;
    for (int k = 0; k < m; k++)
        ans = min(ans, dp[n][k]);
    cout << ans << endl;
    return 0;
}