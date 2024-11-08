#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> dp(n + 1);
    vector<ll> c = {};
    for (int i = 0; i < n; i++)
        dp[i + 1] = dp[i] + (a[i] < i + 1);
    for (int i = 0; i < n; i++)
        if (a[i] < i + 1) c.push_back(i);
    ll ans = 0;
    for (auto &x : c) {
        ll l = 0;
        ll r = c.size();
        while (l < r) {
            ll m = (l + r) / 2;
            if (c[m] + 1 < a[x]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans += r;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}