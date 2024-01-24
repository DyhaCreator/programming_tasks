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
    vector<vector<int >> dp(n, vector<int>(m));
    vector<int>prev(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1;
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < j; l++) {
                        if (dp[k][l] + 1 >= dp[i][j] && a[k] == b[l] && a[k] < a[i]) {
                            dp[i][j] = dp[k][l] + 1;
                            prev[i] = k;
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
    int pos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] >= max) {
                max = dp[i][j];
                pos = i;
            }
        }
    }
    cout << max << endl;
    if (max > 0) {
        vector<int>ans = {};
        while (pos > -1) {
            ans.push_back(a[pos]);
            pos = prev[pos];
        }
        reverse(ans.begin(), ans.end());
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}