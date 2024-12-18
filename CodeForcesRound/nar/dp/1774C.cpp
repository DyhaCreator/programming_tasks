#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n - 1);
    dp[0] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = i + 1;
        }
    }
    for (auto &x : dp)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}