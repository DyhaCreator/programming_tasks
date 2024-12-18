#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll m, n;
    cin >> m >> n;
    ll a = 1, b = 1, c = 0, d = 0,e = 0;;
    while (true) {
        if (a == 0 && b == 1) break;
        b += a;
        a = b - a;
        a = a % m;
        b = b % m;
        d += a;
        c++;
    }
    d += b;
    a = 0;
    b = 1;
    for (int i = 0; i < n % (c + 1) - 1; i++) {
        b += a;
        a = b - a;
        a = a % m;
        b = b % m;
        e += a;
    }
    cout << d * (n / (c + 1)) + e << endl;
    return 0;
}