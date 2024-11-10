#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> dp(n + 1);
    int mx = 0;
    for (int i = 4; i <= n; i++) {
        string s = a.substr(i - 4, 4);
        dp[i] = mx;
        if (s == ">>->" || s == "<-<<")
            dp[i]++;
        mx = max(mx, dp[i - 3]);
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}