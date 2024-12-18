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
    vector<ll> dp(n);
    vector<ll> count(1000000, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = count[500000 + a[i] - i] + a[i];
        count[500000 + a[i] - i] += a[i];
    }
    ll ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}