#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int th = 0;
    int len = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && th == 0) {
            if (len == 1) {
                ans++;
            } else {
                len = 1;
                th = 1 - th;
            }
        }
        if (a[i] == 0 && th == 1) {
            len = 1;
            th = 1 - th;
        }
        if (len == 2) {
            len = 0;
            th = 1 - th;
        }
        len++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}