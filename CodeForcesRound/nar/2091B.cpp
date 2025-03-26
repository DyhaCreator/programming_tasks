#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    ll l = 0;
    for (auto &x : a) {
        if ((l + 1) * x >= k) {
            ans++;
            l = 0;
        } else {
            l++;
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