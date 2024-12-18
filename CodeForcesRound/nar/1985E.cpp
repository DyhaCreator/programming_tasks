#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll ans = -INF;
    for (ll tx = 1; tx <= min(k, x); tx++) {
        for (ll ty = 1; ty <= min(k, y); ty++) {
            ll tz = k / (tx * ty);
            if (tx * ty * tz == k) {
                // cout << tx << " " << ty << " " << tz << endl;
                ll tans = (x - tx + 1) * (y - ty + 1) * (z - tz + 1);
                // cout << tans << endl;
                if (tans >= 0)
                    ans = max(tans, ans);
            }
        }
    }
    cout << ((ans == -INF)?0:ans) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}