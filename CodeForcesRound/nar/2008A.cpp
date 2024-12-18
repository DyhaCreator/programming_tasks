#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    dp[0][0] = 1;
    for (int y = 0; y <= a; y++) {
        for (int x = 0; x <= b; x++) {
            if (y == 0 && x == 0) continue;
            dp[y][x] = 0;
            if (y >= 2 && x >= 1) dp[y][x] = max(dp[y][x], dp[y - 2][x - 1]);
            if (y >= 2) dp[y][x] = max(dp[y][x], dp[y - 2][x]);
            if (x >= 2) dp[y][x] = max(dp[y][x], dp[y][x - 2]);
        }
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << ((dp[a][b])?"YES":"NO") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}