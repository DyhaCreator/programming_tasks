#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<vector<uint16_t >> dp = vector<vector<uint16_t >> (n + 2, vector<uint16_t>(n + 2, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int x = j + i;
            int y = j + 1;
            if (str[x - 1] == str[y - 1]) {
                dp[y][x] = dp[y + 1][x - 1];
            } else {
                dp[y][x] = dp[y + 1][x - 1] + 1;
            }
            if (dp[y][x] <= k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}