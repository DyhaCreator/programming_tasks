#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    double a, b;
    cin >> a >> b;
    if (a == b) {
        printf("%.6f\n", 1.0 / 4.0);
    } else if (a > b) {
        printf("%.6f\n", 2 * (a * a + b * b));
    } else {
        printf("%.6f\n", (a * a + b * b) / 2.0);
    }
    return 0;
}