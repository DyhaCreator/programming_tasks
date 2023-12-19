#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int f(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll>m = vector<ll>(n + 1);
    for (int i = 0; i < n + 1; i++) {
        m[i] = f(i);
        //cout << m[i] << " ";
    }

    vector<vector<ll>>dp = vector<vector<ll>>(n + 2, vector<ll>(n + 3));
    for (int y = 1; y < n + 1; y++) {
        for (int x = 2; x < n + 2; x++) {
            if (y >= (x - 1)) {
                dp[y][x] = max(dp[y][x - 1], dp[y - (x - 1)][x] + m[x - 1]);
            } else {
                dp[y][x] = dp[y][x - 1];
            }
        }
    }
    cout << dp[n][n + 1] << endl;
    return 0;
}