#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> dp(n);
    int index = 0;
    while (a[index] == 'B' && b[index] == 'B' && index < n) {
        dp[index] = 3;
        index++;
    }
    if (a[0] != 'B' && b[0] == 'B') dp[0] = 1;
    if (a[0] == 'B' && b[0] != 'B') dp[0] = 2;
    index = max(index, 1);
    for (int i = index; i < n; i++) {
        if (a[i] != 'B' && b[i] != 'B') {
            dp[i] = 0;
        } else if (a[i] != 'B' && b[i] == 'B') {
            if (dp[i - 1] == 1 || dp[i - 1] == 3) dp[i] = 1;
            else dp[i] = 0;
        } else if (a[i] == 'B' && b[i] != 'B') {
            if (dp[i - 1] == 2 || dp[i - 1] == 3) dp[i] = 2;
            else dp[i] = 0;
        } else {
            if (dp[i - 1] == 2) {
                dp[i] = 1;
            } else if (dp[i - 1] == 1) {
                dp[i] = 2;
            } else if (dp[i - 1] == 3) {
                dp[i] = 3;
            }
        }
    }
    if (dp[n - 1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}