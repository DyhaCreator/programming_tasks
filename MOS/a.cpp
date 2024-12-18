#include <iostream>
#define ll long long
using namespace std;

ll upper(ll x, ll y) {
    return (x + y - 1) / y;
}

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    n++;
    ll i = (n / (a * b) * (a + c));
    ll j = upper((n - n / (a * b) * (a * b)), b);
    if (j == 0) {
        i -= c;
    }
    cout << i + j << endl;
    return 0;
}