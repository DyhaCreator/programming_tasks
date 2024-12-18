#include <iostream>
#define ll long long
using namespace std;

int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

void f(int a, int b, int c) {
    int la = a;
    int lb = b;
    int x = 0, y = 1, prev_x = 1, prev_y = 0;
    while (b != 0 && a != 0) {
        int q = a / b;
        int buffer = a;
        a = b;
        b = buffer % b;
        buffer = x;
        x = prev_x - q * x;
        prev_x = buffer;
        buffer = y;
        y = prev_y - q * y;
        prev_y = buffer;
    }
    cout << a << " " << prev_x * (c / nod(la, lb)) << " " << prev_y * (c / nod(la, lb)) << endl;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c % nod(a, b) != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    f(a, b, c);
    return 0;
}