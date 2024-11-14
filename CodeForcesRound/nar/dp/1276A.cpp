#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n);
    vector<int> dplast(n, -2);
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1];
        dplast[i] = dplast[i - 1];
        if (s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e') {
            if (dplast[i] < i - 2) {
                if (i < n - 1 && s[i + 1] == 'e') {
                    dp[i] = dp[i - 1] + 1;
                    dplast[i] = i - 1;
                } else {
                    dp[i] = dp[i - 1] + 1;
                    dplast[i] = i;
                }
            }
        } else if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o') {
            if (i < n - 1 && s[i + 1] == 'n') {
                dp[i] = dp[i - 1] + 1;
                dplast[i] = i;
            } else {
                dp[i] = dp[i - 1] + 1;
                dplast[i] = i - 1;
            }
        }
    }
      cout << dp[n - 1] << endl;
    int index = dplast[n - 1];
    while (index > 0) {
        cout << index + 1 << " ";
        index = dplast[index - 1];
    }
    cout << endl;
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;
    for (auto &x : dplast)
        cout << x << " ";
    cout << endl;*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}