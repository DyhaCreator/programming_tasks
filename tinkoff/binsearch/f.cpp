#include <iostream>

#define ll long long

using namespace std;

int main() {
    ll N, x, y;
    cin >> N >> x >> y;
    ll l = min(x, y);
    ll r = N * x * y;
    while (l < r) {
        ll m = (l + r) / 2;
        if ((1 + (m - min(x, y)) / x + (m - min(x, y)) / y) < N) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}