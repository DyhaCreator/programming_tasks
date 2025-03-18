#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void rec(ll l, ll r, ll lm, ll rm, vector<ll> &a) {
    if (l >= lm && r <= rm) {
        a.push_back(r - l);
        return;
    }
    ll m = (l + r) / 2;
    if (m > lm) {
        rec(l, m, lm, rm, a);
    }
    if (m < rm) {
        rec(m, r, lm, rm, a);
    }
}

void solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int n = 1;
    while (n < r1 || n < r2)
        n *= 2;
    vector<ll> a = {};
    vector<ll> b = {};
    rec(0, n, l1, r1, a);
    rec(0, n, l2, r2, b);
    ll ans = 0;
    for (auto &x : a) {
        for (auto &y : b) {
            ans += max(x, y) / min(x, y);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}