#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x = -1;
    int y = -1;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

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
    vector<vector<int2>>prev(n + 1, vector<int2>(m + 1, int2(-1, -1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] != b[j - 1]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1;
                //cout << i << " " << j << endl;
                for (int k = 1; k < i; k++) {
                    for (int l = 1; l < j; l++) {
                        //cout << dp[k][l] + 1 << " " << a[k - 1] << " " << a[i - 1] << endl;
                        if (dp[k][l] + 1 > dp[i][j] && a[k - 1] < a[i - 1]) {
                            dp[i][j] = dp[k][l] + 1;
                            prev[i][j] = k - 1;
                        }
                    }
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] > max) {
                max = dp[i][j];
            }
        }
    }
    cout << max << endl;
    return 0;
}