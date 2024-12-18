#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int len = 4;

void solve() {
    int n;
    cin >> n;
    int x0 = 0;
    int x1 = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = (i + 2);
        int y = 0;
        while ((1 << y) <= x) y++;
        if ((1 << (y - 1)) == x) {
            x = x | (1 << 30);
        }
        if (i == 0) {
            x = x | (1 << 29);
        }
        if (i % 2 == 0) {
            x0 = x0 ^ x;
        } else {
            x1 = x1 ^ x;
        }
        cout << x << " ";
    }
    cout << (x0 ^ x1) << endl;
    // cout << x0 << " " << x1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}