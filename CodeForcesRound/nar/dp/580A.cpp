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
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}