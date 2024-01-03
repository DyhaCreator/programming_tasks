#include <iostream>
#include <vector>
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

vector<int> f2(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        vector<int>g = f2(b, a % b);
        return {g[0], g[2], g[1] - g[2] * (a / b)};
    }
}

int main() {
    int a, p;
    cin >> a >> p;
    int y = 1;
    while ((p * y + 1) % a != 0) {
        y++;
    }
    cout << (p * y + 1) / a << endl;
    return 0;
}