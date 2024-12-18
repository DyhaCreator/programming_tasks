#include <iostream>
#include <cmath>
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
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << endl;
        return 0;
    }
    int maxGcd = gcd((n + 1) / 2, n / 2);
    int a = n / 2;
    for (int i = n / 2; i > maxGcd; i--) {
        //cout << i << " " << n - i << "  " << gcd(i, n - i) << endl;
        int g = gcd(i, n - i);
        if (g > maxGcd) {
            maxGcd = g;
            a = i;
        }
    }
    cout << a << " " << n - a << endl;
    return 0;
}