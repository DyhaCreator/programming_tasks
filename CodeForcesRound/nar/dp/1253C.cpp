#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    vector<ll> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = pref[i + 1];
        if (i >= m) {
            dp[i + 1] += dp[i + 1 - m];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n";
    return 0;
}