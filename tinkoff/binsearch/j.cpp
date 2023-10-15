#include <iostream>
#define ll long long
using namespace std;

unsigned ll n, a, b, w, h;

unsigned ll F1(ll m) {
    return (w / (a + m * 2)) * (h / (b + m * 2));
}

unsigned ll F2(ll m) {
    return (w / (b + m * 2)) * (h / (a + m * 2));
}

int main() {
    cin >> n >> a >> b >> w >> h;

    unsigned ll l = 0;
    unsigned ll r = 1000000000000000000LL + 1;
    while (l < r - 1) {
        unsigned ll m = (l + r) / 2;
        if (F1(m) < n && F2(m) < n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l << endl;
    return 0;
}