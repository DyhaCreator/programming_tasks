#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int th(int a) {
    int y = 0;
    while (y * y * y < a) {
        y++;
    }
    return y;
}

int secB(int a) {
    ll l = 0;
    ll r = a + 1;
    while (l < r) {
        unsigned ll m = (l + r) / 2;
        if (m * m < a) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}

int main() {
    int a, b, k, ans = 0;
    cin >> a >> b >> k;

    for (int y = th(a); y * y * y <= b; y++) {
        for (int x = secB(a); x * x * x <= b; x++) {
            //cout << x << " " << y << endl;
            if (abs(x * x - y * y * y) <= k) {
                //cout << "yes" << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}