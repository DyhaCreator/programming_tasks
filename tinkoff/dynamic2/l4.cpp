#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x = 0, y = 0;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    ll n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return 0;
    }
    vector<vector<int2 >> dp = vector<vector<int2 >> (n + 1, vector<int2>(k));
    dp[0] = vector<int2>(k, int2(1, 1));
    for (int y = 1; y < n; y++) {
        for (int x = 0; x < k; x++) {
            for (int i = 0; i < x; i++) {
                dp[y][x].x = (dp[y][x].x + dp[y - 1][i].y) % int(1e9 + 7);
            }
            for (int i = x + 1; i < k; i++) {
                dp[y][x].y = (dp[y][x].y + dp[y - 1][i].x) % int(1e9 + 7);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += dp[n - 1][i].x + dp[n - 1][i].y;
    }
    cout << ans % int(1e9 + 7)<< endl;
    return 0;
}