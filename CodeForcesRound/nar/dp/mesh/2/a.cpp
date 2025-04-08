#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<vector<int>> cnt(26);
    vector<vector<int>> cnt2(n + 1, vector<int>(26));
    vector<vector<int>> dp(n + 1, vector<int>(26));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j != a[i] - 'a') {
                cnt[j].push_back(i);
            }
        }
        for (int j = 0; j < 26; j++) {
            if (a[i] - 'a' == j) {
                cnt2[i + 1][j] = cnt2[i][j] + 1;
            }
        }
        
        for (int j = 0; j < 26; j++) {
            if (k == 0) {
                dp[i][j] = 0;
            } else if (cnt[j].size() >= k) {
                dp[i][j] = i - cnt[j][cnt[j].size() - k] + 1 + cnt2[cnt[j][cnt[j].size() - k]][j];
            } else {
                dp[i][j] = i + 1;
            }
        }
        /*for (auto &x : cnt) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }*/
    }
    int ans = 0;
    for (auto &x : dp) {
        for (auto &y : x)
            ans = max(ans, y);
    }
    for (auto &x : cnt2) {
        for (auto &y : x)
            ans = max(ans, y);
    }
    cout << ans << endl;
    /*for (auto &x : dp)
        cout << x[0] << " " << x[1] << endl;*/
    return 0;
}