#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    for (auto &x : a)
        if (x == 'm' || x == 'w') {
            cout << 0 << endl;
            return 0;
        }
    int n = a.size();
    vector<ll> dp(n + 1);
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] && (a[i] == 'u' || a[i] == 'n')) {
            dp[i + 1] = (dp[i - 1] + dp[i]) % 1000000007;
        } else {
            dp[i + 1] = dp[i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}