#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
        ll buff = a;
        a = b;
        b = buff;
    }
    b -= a - 1;
    a = 1;
    if (b == 1) {
        cout << n / 2 << endl;
        return 0;
    }
    if (b > n / 2 + 1)
        b = n - (b - 1) + 1;
    // cout << a << " " << b << endl;
    ll f = n - b;
    ll s = (b - 2) * 2 + (n - (b + (b - 2) * 2) + 1) / 2;
    ll t = (n - (b + b - 2)) - (n - (b + b - 2)) / 3 + b - 2;
    cout << min(f, min(s, t)) << endl;
    // cout << f << " " << s << " " << t << endl;
    return 0;
}