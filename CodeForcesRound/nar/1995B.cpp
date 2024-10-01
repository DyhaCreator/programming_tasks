#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int j = 0;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        while (j < i && (abs(a[j] - a[i]) > 1 || sum > m)) {
            sum -= a[j];
            j++;
        }
        ans = max(ans, sum);
        // cout << sum << " " << j << " " << i << endl;
    }
    if (ans > m) {
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}