#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 1e10 + 7;

ll sq(ll n) {
    ll l = 0;
    ll r = 1e10 + 7;
    while (l < r) {
        ll m = (l + r) / 2;
        if (m * m < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (r * r != n) r--;
    return r;
}

void solve() {
    ll k;
    cin >> k;
    ll l = 0;
    ll r = INF;
    while (l < r) {
        ll m = (l + r) / 2;
        // cout << m << " " << sq(m) << " " << m - sq(m) << endl;
        if (m - sq(m) < k) {
            l = m + 1;
        } else {
            r = m;
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