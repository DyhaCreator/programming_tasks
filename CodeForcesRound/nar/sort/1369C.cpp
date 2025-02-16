#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(k);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0;
    int r = n - 1;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        if (b[i] > 2) {
            ans += a[l] + a[r];
            l += b[i] - 1;
            r--;
        } else if (b[i] == 2) {
            ans += a[r] + a[r - 1];
            r -= 2;
        } else {
            ans += a[r] + a[r];
            r--;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}