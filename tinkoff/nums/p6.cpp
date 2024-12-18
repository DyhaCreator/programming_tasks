#include <iostream>
#define ll long long
using namespace std;

void f(int a, int p) {
    int s0 = 1, s1 = 0, t0 = 0, t1 = 1;
    while (a > 0) {
        int q = p / a;
        int newR = p % a;
        int newS = s0 - q * s1;
        int newT = t0 - q * t1;
        p = a;
        a = newR;
        s0 = s1;
        s1 = newS;
        t0 = t1;
        t1 = newT;
    }
    /*if (t0 < 0) {
        t0 = -t0 + 1;
    }*/
    cout << t0 << " " << s0 << endl;
}

int main() {
    int a, p;
    cin >> a >> p;
    f(a, p);
    return 0;
}