#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    ll a, b, d;
    cin >> a >> b >> d;
    if ((a + b) * 10 / 2 % 10 == 0) {
        ll f = abs((a + b) / 2);
        cout << (a + b) / 2 << " " << min(abs((f + d) / d * d - f), abs(f / d * d - f)) << endl;
    } else {
        ll f1 = (a + b) / 2;
        int n = 0;
        if ((a + b) / 2.0 >= 0) {
            n = +1;
        } else {
            n = -1;
        }
        ll f2 = ceil(abs((a + b) / 2.0));
        // cout << f1 << " " << f2 << endl;
        if (min(abs((f1 + d) / d * d - f1), abs(f1 / d * d - f1)) <
            min(abs((f2 + d) / d * d - f2), abs(f2 / d * d - f2))) {
            cout << f1 << " ";
            f1 = abs(f1);
            cout << min(abs((f1 + d) / d * d - f1), abs(f1 / d * d - f1)) << endl;
        } else {
            cout << f2 * n << " ";
            f2 = abs(f2);
            cout << min(abs((f2 + d) / d * d - f2), abs(f2 / d * d - f2)) << endl;
        }
    }
    return 0;
}