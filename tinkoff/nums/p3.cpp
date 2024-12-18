#include <iostream>
#define ll long long
using namespace std;

ll f(ll a, ll b) {
    ll x = 0, y = 1, prev_x = 1, prev_y = 0;
    while (b != 0) {
        ll q = a / b;
        ll buffer = a;
        a = b;
        b = buffer % b;
        buffer = x;
        x = prev_x - q * x;
        prev_x = buffer;
        buffer = y;
        y = prev_y - q * y;
        prev_y = buffer;
    }
    cout << prev_x << " " << prev_y << endl;
    return prev_x, prev_y;
}

int main() {
    int a, p;
    cin >> a >> p;
    cout << f(a, p) << "\n";
    return 0;
}