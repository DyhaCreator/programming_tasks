#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int nod(int a, int b) {
    if (a == 1 && b == 1) return 1;
    while (b > 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    if (l % 2 == 0) l++;
    for (int i = l; i <= r; i += 4) {
        if (i < r - 1) ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}