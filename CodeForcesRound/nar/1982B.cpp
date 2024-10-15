#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int q = 0;
    while (k > 0 && q < 1e18 && x > 1) {
        // cout << (x + y - 1) / y * y << endl;
        if ((x + y) / y * y - x < k) {
            k -= (x + y) / y * y - x;
            x = (x + y) / y * y;
        } else {
            x += k;
            k = 0;
        }
        // cout << k << " " << x << endl;
        while (x % y == 0)
            x /= y;
        // cout << k << " " << x << endl;
        q++;
    }
    if (k > 0) {
        x += k % (y - 1);
    }
    cout << x << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}