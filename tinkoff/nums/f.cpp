#include <iostream>
#define ll long long
using namespace std;

int gcd(int a, int b) {
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int f = b * d / gcd(b, d);
    int e = (a * (f / b)) + (c * (f / d));
    cout << e / gcd(e, f) << " " << f / gcd(e, f) << endl;
    return 0;
}