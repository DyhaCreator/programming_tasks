#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    int t;
    cin >> t;
    vector<int>b = vector<int>(t);
    for (auto &x : b)
        cin >> x;
    vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(t + 1));
    //vector<vector<vector<int16_t>>>dp = vector<vector<vector<int16_t>>>(n + 1, vector<vector<int16_t>>(t + 1, vector<int16_t>()));
    for (int y = 1; y < n + 1; y++) {
        for (int x = 1; x < t + 1; x++) {
            if (a[y - 1] == b[x - 1]) {
                dp[y][x] = dp[y - 1][x - 1] + 1;
            } else {
                dp[y][x] = max(dp[y][x - 1], dp[y - 1][x]);
                /*if (dp[y][x - 1] > dp[y - 1][x]) {
                    dp[y][x] = dp[y][x - 1];
                } else {
                    dp[y][x] = dp[y - 1][x];
                }*/
            }
            //cout << dp[y][x] << " ";
        }
        //cout << endl;
    }
    //cout << dp[n][t] << endl;
    vector<int>ans = vector<int>();
    int y = n;
    int x = t;
    while (y != 0 && x != 0) {
        //cout << y << " " << x << endl;
        if (a[y - 1] == b[x - 1]) {
            ans.push_back(a[y - 1]);
            x--;
            y--;
        } else {
            if (dp[y - 1][x] > dp[y][x - 1]) {
                y--;
            } else {
                x--;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    vector<int>dpV = vector<int>(ans.size() + 1, 0);
    for (int i = 1; i < dpV.size(); i++) {

    }

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}