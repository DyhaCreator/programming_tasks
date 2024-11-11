#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> count(256, -1);
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        l[i] = count[s[i]];
        count[s[i]] = i;
    }
    vector<int> dp(n);
    dp[0] = 1;
    int li = -1;
    for (int i = 1; i < n; i++) {
        if (l[i] <= li) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = dp[i - 1] - 1;
            li = i;
        }
    }
    cout << dp[n - 1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}