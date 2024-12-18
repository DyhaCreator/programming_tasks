#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int>a = vector<int>(n);
        vector<int>b = vector<int>(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        vector<vector<int>>dp = vector<vector<int>>(k + 1, vector<int>(n + 1));
        vector<vector<int>>dp2 = vector<vector<int>>(k + 1, vector<int>(n + 1));
        for (int y = 1; y < k + 1; y++) {
            for (int x = 1; x < n + 1; x++) {
                dp[y][x] = dp[y][x - 1];
                if (dp[y - 1][x - 1] + a[x - 1] > dp[y][x]) {
                    dp[y][x] = dp[y - 1][x - 1];
                    dp2[y][x] = 1;
                }
                if (dp2[y - 1][x] == 1 && dp[y - 1][x] + b[x - 1] > dp[y][x]) {
                    dp2[y][x] = 1;
                    dp[y][x] = dp[y - 1][x] + b[x - 1];
                }
                cout << dp[y][x] << " ";
            }
            cout << endl;
        }
        for (int y = 0; y < k + 1; y++) {
            for (int x = 0; x < n + 1; x++) {
                cout << dp2[y][x] << " ";
            }
            cout << endl;
        }
        cout << dp[k][n] << endl;
    }
    return 0;
}