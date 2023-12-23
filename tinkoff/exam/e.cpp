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
    int a, b, c, i, j;
    cin >> a >> b >> c >> i >> j;
    ll l = gcd(gcd(a, b), c);
    cout << l << endl; 
    return 0;
}