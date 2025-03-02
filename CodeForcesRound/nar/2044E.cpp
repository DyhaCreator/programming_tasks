#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll st = 1;
    ll ans = 0;
    while (st <= r2) {
        ll l = max(l1, (l2 + st - 1) / st);
        ll r = min(r1, r2 / st);
        if (r >= l) ans += r - l + 1;
        st *= k;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}