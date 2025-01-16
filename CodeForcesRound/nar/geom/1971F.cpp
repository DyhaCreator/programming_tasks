#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 1; i <= n; i++) {
        ll l = 0;
        ll r = n * 2;
        while (l < r) {
            ll m = (l + r) / 2;
            if (i * i + m * m < n * n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        a[i - 1].F = r;
        l = 0;
        r = n * 2;
        while (l < r) {
            ll m = (l + r) / 2;
            if (i * i + m * m < (n + 1) * (n + 1)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        a[i - 1].S = r;
    }
    ll ans = 0;
    for (auto &x : a)
        ans += x.S - x.F;
    ans *= 4;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}