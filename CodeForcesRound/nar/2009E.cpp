#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
ll n, k;

ll f(ll m) {
    return ((k + m) * (m - k + 1) - (m + n + k) * (n + k - m - 1)) / 2;
}

void solve() {
    cin >> n >> k;
    ll l = k;
    ll r = k + n - 1;
    for (int i = 0; i < 103; i++) {
        ll m = (l + r) / 2;
        // cout << (double)(k + m)/ 2.0 * (m - k + 1) - (double)(m + n + k) / 2.0 * (n + k - m - 1) << endl;
        // cout << m << " " << f(m) << endl;
        if (f(m) < 0) {
            l = m;
        } else {
            r = m;
        }
    }
    // cout << f(l) << " " << f(r) << endl;
    cout << min(abs(f(l)), abs(f(r))) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}