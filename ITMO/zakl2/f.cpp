#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    ll x = 1;
    ll g = 0;
    ll n, r;
    cin >> n;
    r = 123231312;
    while (r > 0) {
        ll m = r % 100;
        ll l = (m / 10) * n + (m % 10);
        if (l >= 10) {
            l = (l / 10) * 10 + (l % 10);
            g = l * x + g;
            x *= 100;
        } else {
            g = l * x + g;
            x *= 100;
        }
        r /= 100;
    }
    cout << g << endl;
    return 0;
}