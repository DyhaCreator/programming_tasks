#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll f(ll k, ll n, ll m) {
    return (m / (k + 1) * k + m % (k + 1)) * n;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0;
    ll r = m;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (f(mid, n, m) < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}