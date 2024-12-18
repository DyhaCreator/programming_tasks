#include <iostream>

int main() {
    float a, b, c, d;
    std::cin >> a >> b >> c >> d;
    float l = -1000000;
    float r = 10001000;
    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2.0;
        if ((a * (m * m * m) + b * (m * m) + c * m + d) < 0) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%.4f\n", (l + r) / 2.0);
    return 0;
}