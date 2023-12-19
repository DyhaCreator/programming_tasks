#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
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
    ll a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b) << endl;
    return 0;
}