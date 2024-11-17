#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;

const int INF = 1e9 + 7;

int main() {
    ll a, b, c;
    ll d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    if (a + b > c && a + c > b && b + c > a &&
        d + e > f && d + f > e && e + f > d) {
        cout << 1 << endl;
        if ((a == d && f == c) || (a == f && d == c)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}