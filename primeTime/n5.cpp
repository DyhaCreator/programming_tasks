#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int f1(int a, int b, int c) {
    int d = min(a, b);
    a -= d;
    b -= d;
    d = min(a, c);
    a -= d;
    c -= d;
    return a;
}

int f2(int a, int b, int c) {
    int d = min(a, b);
    a -= d;
    b -= d;
    return a;
}

int f3(int a, int b, int c) {
    int d = min(a, c);
    a -= d;
    c -= d;
    d = min(a, b);
    a -= d;
    b -= d;
    return a;
}

int f4(int a, int b, int c) {
    int d = min(a, b);
    a -= d;
    b -= d;
    d = min(b, c);
    b -= d;
    c -= d;
    d = min(a, c);
    a -= d;
    c -= d;
    return a;
}

int f5(int a, int b, int c) {
    int d = min(b, c);
    b -= d;
    c -= d;
    d = min(a, b);
    a -= d;
    b -= d;
    d = min(a, c);
    a -= d;
    c -= d;
    return a;
}

int f6(int a, int b, int c) {
    int d = min(b, c);
    b -= d;
    c -= d;
    d = min(a, c);
    a -= d;
    c -= d;
    d = min(a, b);
    a -= d;
    b -= d;
    return a;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (f1(a, b, c) != 0 && 
        f2(a, b, c) != 0 && 
        f3(a, b, c) != 0 && 
        f4(a, b, c) != 0 && 
        f5(a, b, c) != 0 && 
        f6(a, b, c) != 0) {
        cout << "Sure\n";
    } else if (f1(a, b, c) != 0 ||
        f2(a, b, c) != 0 ||
        f3(a, b, c) != 0 || 
        f4(a, b, c) != 0 || 
        f5(a, b, c) != 0 || 
        f6(a, b, c) != 0) {
        cout << "Maybe\n";
    } else {
        cout << "Never\n";
    }
    return 0;
}