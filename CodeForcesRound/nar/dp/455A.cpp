#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> count(100002);
    for (auto &x : a)
        count[x]++;
    vector<ll> dp(100001);
    dp[1] = count[1];
    for (ll i = 2; i < 100001; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
    ll ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}