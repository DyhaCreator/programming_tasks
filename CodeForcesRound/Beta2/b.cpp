#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll f(ll n) {
    ll ans = 0;
    while (n % 10 == 0) {
        ans++;
        n /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<ll>>map = vector<vector<ll>>(n, vector<ll>(n));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<ll>>dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1, 1));
    vector<vector<char>>dp2 = vector<vector<char>>(n + 1, vector<char>(n + 1));
    for (int y = 1; y < n + 1; y++) {
        for (int x = 1; x < n + 1; x++) {
            if (y > 1 && x > 1) {
                if (f(dp[y - 1][x] * map[y - 1][x - 1]) <= f(dp[y][x - 1] * map[y - 1][x - 1])) {
                    dp[y][x] = dp[y - 1][x] * map[y - 1][x - 1];
                    dp2[y][x] = 'D';
                } else {
                    dp[y][x] = dp[y][x - 1] * map[y - 1][x - 1];
                    dp2[y][x] = 'R';
                }
            } else if (y > 1) {
                dp[y][x] = dp[y - 1][x] * map[y - 1][x - 1];
                dp2[y][x] = 'D';
            } else if (x > 1) {
                dp[y][x] = dp[y][x - 1] * map[y - 1][x - 1];
                dp2[y][x] = 'R';
            } else {
                dp[y][x] = map[y - 1][x - 1];
                dp2[y][x] = '0';
            }
        }
    }
    cout << f(dp[n][n]) << endl;
    int y = n;
    int x = n;
    vector<char>ans = {};
    while (dp2[y][x] != '0') {
        ans.push_back(dp2[y][x]);
        //cout << dp2[y][x] << " ";
        if (dp2[y][x] == 'D') {
            y--;
        } else {
            x--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x;
    cout << endl;
    //cout << dp2[n][n] << endl;
    return 0;
}