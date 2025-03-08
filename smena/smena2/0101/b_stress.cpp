#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll solve1(ll n, ll a, ll b) {
    if (a > b) {
        ll buff = a;
        a = b;
        b = buff;
    }
    b -= a - 1;
    a = 1;
    // cout << a << " " << b << endl;
    if (b == 1) {
        return n / 2;
    }
    if (b < n / 2 + 1) {
        return (b - a - 1) * 2 + (n - (b + (b - a - 1) * 2) + 1) / 2;
    } else if (b > n / 2 + 1) {
        b = n - (b - 1) + 1;
        // cout << a << " " << b << endl;
        return (b - a - 1) * 2 + (n - (b + (b - a - 1) * 2) + 1) / 2;
    } else {
        return (n - 1) / 2;
    }
}

ll solve2(ll n, ll a, ll b) {
    if (a > b) {
        ll buff = a;
        a = b;
        b = buff;
    }
    b -= a - 1;
    a = 1;
    if (b == 1) {
        return n / 2;
        return 0;
    }
    if (b <= n / 2 + 1)
        b = n - (b - 1) + 1;

    // cout << a << " " << b << endl;
    ll f = (b - (n + 1) / 2 - 1) * 2 + (n - b);
    ll s = (n - b) * 2 + (b - (n + 1) / 2 - 1);
    return max(min(f, s), (n - 1) / 2);
}

int main() {
    for (int n = 1; n <= 10; n++) {
        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                if (solve2(n, a, b) != solve1(n, a, b)) {
                    cout << n << " " << a << " " << b << " " << solve1(n, a, b) << " " << solve2(n, a, b) << endl;
                }
            }
        }
    }
    return 0;
}