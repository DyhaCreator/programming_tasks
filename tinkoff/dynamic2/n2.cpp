#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll f(ll i) {
    ll ans = 0;
    while (i > 0) {
        ans += (i % 10) * (i % 10);
        i /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll>a = vector<ll>(n + 1, 0);
    vector<vector<ll>>dp = vector<vector<ll>>(n + 2, vector<ll>(n + 3, 0));
    for (ll i = 0; i < n + 1; i++) {
        a[i] = f(i);
        for (ll x = 1; x <= i; x++) {
            if (i >= x - 1 && dp[i - (x - 1)][x] + a[x - 1] > dp[i][x - 1]) {
                dp[i][x] = dp[i - (x - 1)][x] + a[x - 1];
            } else {
                dp[i][x] = dp[i][x - 1];
            }
        }
        for (ll y = 1; y <= i; y++) {
            dp[y][i + 1] = 1;
            if (y >= i && dp[y - i][i + 1] + a[i] > dp[y][i]) {
                dp[y][i + 1] = dp[y - i][i + 1] + a[i];
            } else {
                dp[y][i + 1] = dp[y][i + 1 - 1];
            }
        }
        a[i] = dp[i][i + 1];
        //cout << a[i] << endl;
    }
    cout << a[n] << endl;
    return 0;
}