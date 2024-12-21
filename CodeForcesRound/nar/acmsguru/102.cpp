#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int gcd(int a, int b) {
    while (b != a) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}