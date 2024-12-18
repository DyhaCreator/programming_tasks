#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(int n) {
    vector<int> dp(11);
    ll st = 1;
    for (int i = 1; i < 11; i++) {
        dp[i] = dp[i - 1] + st * (n % 10);
        st *= 10;
        st++;
        n /= 10;
    }
    return dp[10];
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}