#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nod(int a, int b) {
    if (a == 1 || b == 1) return 1;
    while (b > 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a -= c;
    b -= d;
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) {
        cout << 0 << endl;
        return 0;
    }
    int m = max(a, b);
    int n = min(a, b);
    int nd = nod(n, m);
    // cout << m / nod(n, m) << " " << n / nod(n, m) << endl;
    cout << (m / nd + n / nd - 1) * nd << endl;
    return 0;
}