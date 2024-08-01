#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    // cout << a << " " << b << endl;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = gcd_ext(b, a % b, x, y);
    x -= (a / b) * y;
    ll buffer = y;
    y = x;
    x = buffer;
    // cout << x << " " << y << endl;
    return d;
}

int main() {
    ll a, b, c;
    ll x = 0, y = 1;
    cin >> a >> b >> c;
    ll d = gcd_ext(a, b, x, y);
    if (c % d != 0) {
        cout << -1 << endl;
        return 0;
    }
    // cout << x << " " << y << endl;
    ll l = -100000000;
    ll r = +1000000000;
    for (int i = 0; i < 100; i++) {
        ll t = (l + r) / 2;
        if (x * c / d + t * b / d < 0) {
            l = t;
        } else {
            r = t;
        }
    }
    /*int t = -100000000;
    while (x * c / d + t * b / d < 0) {
        t++;
    }*/
    // cout << r << endl;
    cout << x * c / d + r * b / d << " " << y * c / d - a / d * r << endl;
    return 0;
}