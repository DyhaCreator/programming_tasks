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
    vector<ll> cnt(31);
    vector<ll> cost(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 31; j++) {
            if ((a[i] & (1 << j)) > 0) {
                cnt[j]++;
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 31; j++) {
            if ((a[i] & (1 << j)) > 0) {
                cost[i] += (n - cnt[j]) * (1LL << j);
            } else {
                cost[i] += cnt[j] * (1LL << j);
            }
        }
    }
    ll mx = 0;
    for (auto &x : cost)
        mx = max(mx, x);
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}