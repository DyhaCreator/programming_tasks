#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0) {
        if (c == 1) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (a == 0) {
        if (c == 1) {
            cout << b << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (c == a + 1) {
            int l = 0;
            int r = 20;
            while (l < r) {
                ll m = (l + r) / 2;
                if ((1LL << (m + 1)) - 1 < a) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            r--;
            int tr = (1 << (r + 1)) - 1;
            if (b > (tr + 1) - (a - tr)) {
                b -= (tr + 1) - (a - tr);
                cout << r + (a > tr) + (b + a) / (a + 1) + 1 << endl;
            } else {
                cout << r + (a > tr || b > 0) + 1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}