#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll l1, r1, l2, r2;

ll f(ll x0, ll y0, ll s) {
    ll y1 = max(y0, l2);
    ll x1 = max(x0, l1);
    ll y2 = min(y0 + s, r2);
    ll x2 = min(x0 + s, r1);
    if (y1 >= y2 || x2 <= x1) return 0;
    return (y2 - y1) * (x2 - x1);
}

ll rec(ll x0, ll y0, ll s) {
    if (f(x0, y0, s) == s * s)
        return 1;
    ll sum = 0;
    if (f(x0, y0, s / 2) > 0)
        sum += rec(x0, y0, s / 2);
    if (f(x0 + s / 2, y0, s / 2) > 0)
        sum += rec(x0 + s / 2, y0, s / 2);
    if (f(x0, y0 + s / 2, s / 2) > 0)
        sum += rec(x0, y0 + s / 2, s / 2);
    if (f(x0 + s / 2, y0 + s / 2, s / 2) > 0)
        sum += rec(x0 + s / 2, y0 + s / 2, s / 2);
    return sum;
}

void solve() {
    cin >> l1 >> r1 >> l2 >> r2;
    int n = 1;
    while (n < r1 || n < r2)
        n *= 2;
    int ans = rec(0, 0, n);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}