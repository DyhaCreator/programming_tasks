#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;
    sort(b.begin(), b.end());
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        // cout << a << endl;

        if (a < b[0]) {
            // cout << 1111 << endl;
            cout << b[0] - 1 << endl;
            continue;
        }
        if (a > b[m - 1]) {
            // cout << 1111 << endl;
            cout << n - b[m - 1] << endl;
            continue;
        }

        int l = 0;
        int r = m;
        while (l < r) {
            int m = (l + r) / 2;
            if (b[m] < a) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << (b[r - 1] + b[r]) / 2 - b[r - 1] << endl;
        // cout << r << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}