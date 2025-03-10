#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, k;
    cin >> n >> k;
    int64_t l = 0;
    int64_t r = n * k;
    while (l < r) {
        int64_t m = (l + r) / 2;
        if (m - m / n < k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}