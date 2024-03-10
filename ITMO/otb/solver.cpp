#include <iostream>
#define ll long long
using namespace std;

int imp(int a, int b) {
    if (a == 0 && b == 0) return 1;
    if (a == 0 && b == 1) return 1;
    if (a == 1 && b == 0) return 0;
    return 1;
}

int nimp(int a, int b) {
    if (a == 0 && b == 0) return 1;
    if (a == 0 && b == 1) return 0;
    if (a == 1 && b == 0) return 1;
    return 1;
}

bool f(int n) {
    int a = (n & 0b1000) >> 3;
    int b = (n & 0b100) >> 2;
    int c = (n & 0b10) >> 1;
    int d = n & 0b1;
    // cout << a << " " << b << " " << c << " " << d << endl;
    return ((a & b) ^ (b & c)) ^ (c & d);
}

bool f2(int n) {
    int a = (n & 0b1000) >> 3;
    int b = (n & 0b100) >> 2;
    int c = (n & 0b10) >> 1;
    int d = n & 0b1;
    // cout << a << " " << b << " " << c << " " << d << endl;
    return imp(imp((a | b), (b | c)), (c | d));
}

bool f3(int n) {
    int a = (n & 0b1000) >> 3;
    int b = (n & 0b100) >> 2;
    int c = (n & 0b10) >> 1;
    int d = n & 0b1;
    // cout << a << " " << b << " " << c << " " << d << endl;
    return ((a | b) ^ (b | c)) ^ (c | d);
}

bool f4(int n) {
    int a = (n & 0b1000) >> 3;
    int b = (n & 0b100) >> 2;
    int c = (n & 0b10) >> 1;
    int d = n & 0b1;
    // cout << a << " " << b << " " << c << " " << d << endl;
    return nimp(nimp((a | b), (b | c)), (c | d));
}

int main() {
    for (int a = 0; a < 16; a++) {
        // cout << f3(a) << endl;
        if (f(a) && f2(a) && f3(a) && f4(a)) {
            cout << a << endl;
        }
    }
    return 0;
}