#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    double R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) >= R * R) {
        printf("%.6f %.6f %.6f\n", x1, y1, R);
        return 0;
    }
    x2 -= x1;
    y2 -= y1;
    if (x2 == 0 && y2 == 0) {
        printf("%.6f %.6f %.6f\n", x1 + R / 2, y1, R / 2);
        return 0;
    }
    int f = 0;
    if (x2 == 0) {
        f = 1;
        double buff = x2;
        x2 = y2;
        y2 = buff;
    }
    double g = (sqrt(x2 * x2 + y2 * y2) + R) / 2;
    double l = 0;
    double r = 1e6;
    while (r - l > 0.0000001) {
        double m = (l + r) / 2;
        // cout << m << " " << ((double)abs(y2) / abs(x2) * m) << " " << m * m + ((double)abs(y2) / abs(x2) * m) * ((double)abs(y2) / abs(x2) * m) << " " << g * g << endl;
        if (m * m + ((double)abs(y2) / abs(x2) * m) * ((double)abs(y2) / abs(x2) * m) < g * g) {
            l = m;
        } else {
            r = m;
        }
    }
    l = ((double)abs(y2) / abs(x2) * r);
    if (f) {
        double buff = l;
        l = r;
        r = buff;
        buff = x2;
        x2 = y2;
        y2 = buff;
    }
    if (x2 > 0) {
        r *= -1;
        printf("%.6f ", r + x2 + x1);
        r *= -1;
    } else {
        printf("%.6f ", r + x2 + x1);
    }
    if (y2 > 0) {
        l *= -1;
        printf("%.6f ", l + y2 + y1);
        l *= -1;
    } else {
        printf("%.6f ", l + y2 + y1);
    }
    printf("%.6f\n", g);
    return 0;
}