#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int ans = INF;
    if (k == 4) {
        int count = 0;
        for (auto &x : a) {
            if (x % 2 == 0) count++;
            if (x % 4 == 0) count++;
        }
        if (count >= 2) {
            ans = 0;
        } else if (count == 1) {
            ans = 1;
        } else {
            ans = 2;
        }
    }
    for (auto &x : a) {
        if (x % k == 0) ans = 0;
        ans = min(ans, k - x % k);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}