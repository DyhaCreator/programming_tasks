#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;\
    vector<vector<int>>map = vector<vector<int>>(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == -1) {
                dp[y][x] = 1e9;
            } else {
                if (y == 0 && x == 0) {
                    dp[y][x] = map[y][x];
                } else if (y == 0) {
                    dp[y][x] = dp[y][x - 1] + map[y][x];
                } else if (x == 0) {
                    dp[y][x] = dp[y - 1][x] + map[y][x];
                } else {
                    dp[y][x] = std::min(std::min(dp[y - 1][x], dp[y][x - 1]), dp[y - 1][x - 1]) + map[y][x];
                }
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}