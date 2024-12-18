#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

vector<int> dp(1000001);

void solve() {
    int n;
    cin >> n;
    if (dp[n] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    dp[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        if (i >= 2020 && dp[i - 2020] == 1)
            dp[i] = 1;
        if (i >= 2021 && dp[i - 2021] == 1)
            dp[i] = 1;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}