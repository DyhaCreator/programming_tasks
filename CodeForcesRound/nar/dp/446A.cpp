#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp_len(n);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            dp_len[i] = dp_len[i - 1] + 1;
        } else {
            dp_len[i] = 0;
        }
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = dp_len[i] + 1;
        if (i - dp_len[i] > 0) {
            dp[i]++;
            if (dp_len[i] == 0) {
                dp[i] = dp_len[i - 1] + 2;
            } else if (dp_len[i - dp_len[i] - 1] == 0) {
                dp[i] = dp_len[i] + 2;
            } else {
                if (a[i - dp_len[i] + 1] - a[i - dp_len[i] - 1] >= 2) {
                    dp[i] = dp_len[i] + dp_len[i - dp_len[i] - 1] + 2; 
                } else if (a[i - dp_len[i]] - a[i - dp_len[i] - 2] >= 2) {
                    dp[i] = dp_len[i] + dp_len[i - dp_len[i] - 1] + 2; 
                }
            }
        }
    }
    

    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}