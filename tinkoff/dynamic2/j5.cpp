#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int>b(m);
    for (auto &x : b)
        cin >> x;
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    vector<int>prev(n, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1;
                for (int k = 1; k < i; k++) {
                    for (int l = 1; l < j; l++) {
                        if (dp[k][l] + 1 > dp[i][j] && a[k - 1] < a[i - 1] && a[k - 1] == b[l - 1]) {
                            dp[i][j] = dp[k][l] + 1;
                            prev[i - 1] = k - 1;
                        }
                    }
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    /*for (auto &x : prev)
        cout << x << " ";
    cout << endl;*/
    int max = 0;
    int maxX = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] >= max) {
                max = dp[i][j];
                maxX = i - 1;
            }
        }
    }
    vector<int>ans = {};
    cout << max << endl;
    while (maxX != -1) {
        //cout << maxX << endl;
        ans.push_back(a[maxX]);
        maxX = prev[maxX];
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}