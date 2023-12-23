#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    ll a, b, c, i, j;
    cin >> a >> b >> c >> i >> j;
    ll g1 = gcd(a, b);
    ll g2 = gcd(a, c);
    ll g3 = gcd(b, c);
    ll nok = (a * b * c) / (g1 * g2 * g3);
    cout << j / nok - i / nok << endl;
    return 0;
}