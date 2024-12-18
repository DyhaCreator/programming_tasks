#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1000000000000000000 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    if (n % 2 == 0) {
        ll mx = 0;
        for (int i = 1; i < n; i += 2) {
            mx = max(mx, a[i] - a[i - 1]);
        }
        cout << mx << endl;
        return;
    }
    ll ans = INF;
    for (int i = 0; i < n; i+=2) {
        ll mx = 0;
        for (int j = 0; j < n - 1; j += 2) {
            if (j == i) j++;
            mx = max(mx, a[j + 1] - a[j]);
        }
        // cout << mx << endl;
        ans = min(mx, ans);
    }
    cout << max(ans, 1LL) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}