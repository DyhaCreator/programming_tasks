#include <iostream>

#define ll long long

using namespace std;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    ll l = max(w, h);
    ll r = max(w, h) * n;
    while (l < r - 1) {
        ll m = (l + r) / 2;
        if ((m / w) * (m / h) < n) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << r << endl;
    return 0;
}