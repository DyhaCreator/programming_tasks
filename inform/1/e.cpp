#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    double a, n, p;
    cin >> a >> n >> p;
    double sum = a / n;
    for (int i = 0; i < n; i++) {
        a -= sum;
        a += a * p;
    }
    printf("%.2f\n", a);
    return 0;
}