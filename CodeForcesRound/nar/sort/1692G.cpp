#include <algorithm>
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
    int len = 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i] * 2) {
            len++;
        } else {
            len = 1;
        }
        if (len > k)
            ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}