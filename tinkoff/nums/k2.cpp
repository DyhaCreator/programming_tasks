#include <iostream>
#define ll long long
using namespace std;

ll nod(ll a, ll b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    ll n;
    cin >> n;
    ll fx, fy;
    cin >> fx >> fy;
    ll ans = 0;
    ll lx = fx, ly = fy;
    for (ll i = 0; i < n - 2; i++) {
        ll x, y;
        cin >> x >> y;
        ans += nod(abs(x - lx), abs(y - ly));
        lx = x;
        ly = y;
    }
    ll x, y;
    cin >> x >> y;
    ans += nod(abs(fx - x), abs(fy - y)) + nod(abs(x - lx), abs(y - ly));
    cout << ans << endl;
    return 0;
}