#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    double a, b, c, x;
    cin >> a >> b >> c >> x;
    if (x != 0) {
        printf("%.6f\n", sin(((a + b) * x) / 2.0));
    } else {
        printf("%.6f\n", pow(c, pow(b, b + a)));
    }
    return 0;
}