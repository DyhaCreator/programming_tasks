#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> a(r + 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a) {
        int f = 0;
        for (auto &y : a) {
            if ((y ^ x) > r) {
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << x << endl;
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}