#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = 0;
    for (auto &x : a)
        ans += x % 2;
    if (ans == n || ans == 0) {
        ll mx = 0;
        for (auto &x : a)
            mx = max(mx, x);
        cout << mx << endl;
        return;
    }
    ll sum = 0;
    for (auto &x : a)
        sum += x;
    cout << sum - (ans - (ans > 0)) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}