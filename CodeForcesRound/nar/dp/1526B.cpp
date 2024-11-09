#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<int> dp(2000 + 1);
    dp[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        int num = 11;
        while (num <= i) {
            dp[i] = max(dp[i], dp[i - num]);
            num *= 10;
            num++;
        }
    }
    if (n > 2000) {
        cout << "YES" << endl;
    } else {
        if (dp[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}