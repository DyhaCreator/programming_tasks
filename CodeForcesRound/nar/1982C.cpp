#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    int j = 0;
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << a[i] << endl;
        sum += a[i];
        while (sum > r) {
            sum -= a[j];
            j++;
            // cout << sum << endl;
        }
        // cout << i << " " << j << " " << sum << " " << ans << endl;
        if (sum >= l) {
            while (j <= i) {
                sum -= a[j];
                j++;
            }
            ans++;
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