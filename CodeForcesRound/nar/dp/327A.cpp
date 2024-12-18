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
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (a[i] == 1);
    vector<int> suff(n + 1);
    for (int i = n; i > 0; i--)
        suff[i - 1] = suff[i] + (a[i - 1] == 1);
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
        dp[i + 1] = max(dp[i] + (a[i] == 0), pref[i] + (a[i] == 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i] + suff[i]);
    cout << ans << endl;
    return 0;
}