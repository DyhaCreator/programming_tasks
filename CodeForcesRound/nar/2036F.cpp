#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll f(ll n) {
    if (n % 4 == 0) {
        return n;
    } else if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    }
    return 0;
}

void solve() {
    ll l, r, i, k;
    cin >> l >> r >> i >> k;

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}