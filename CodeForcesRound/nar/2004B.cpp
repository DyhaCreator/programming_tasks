#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    int minl = min(l, L);
    int minr = min(r, R);
    int maxl = max(l, L);
    int maxr = max(r, R);
    l = minl;r = minr;
    L = maxl;R = maxr;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (i + 1 >= L && i + 1 <= R) ans++;
    }
    cout << max(1, ans) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}