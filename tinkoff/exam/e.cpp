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
    ll l_ab = a * b / gcd(a, b);
    ll l_lc = l_ab * c / gcd(l_ab, c);
    //cout << l_lc << endl;
    cout << j / l_lc - i / l_lc << endl;
    return 0;
}