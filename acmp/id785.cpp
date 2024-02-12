#include <iostream>
#define ll long long
using namespace std;

bool f(ll n) {
    ll s = n * n;
    while (n > 0) {
        //cout << n << " " << s << endl;
        if (n % 10 != s % 10) {
            return false;
        }
        n /= 10;
        s /= 10;
    }
    return true;
}

int main() {
    ll a, b;
    cin >> a >> b;
    for (ll i = a; i <= b; i++) {
        if (f(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}