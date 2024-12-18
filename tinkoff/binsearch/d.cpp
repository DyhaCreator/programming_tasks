#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    double C;
    cin >> C;
    double l = 0;
    double r = 100000000000;
    while (r - l > 0.0000001) {
        double m = (l + r) / 2.0;
        if (m * m + sqrt(m) < C) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%.6f\n", r);
    return 0;
}