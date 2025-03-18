#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (auto &x : a)
        x = min(x, n - 1);
    vector<ll> pref(m + 1);
    for (int i = 0; i < m; i++)
        pref[i + 1] = pref[i] + a[i];

    vector<ll> dp(m);
    for (ll i = 1; i < m; i++) {
        ll l = 0;
        ll r = i;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (a[mid] + a[i] < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        // cout << a[i] << " " << r << endl;
        dp[i] = a[i] * (i - r) + (pref[i] - pref[r]) - n * (i - r) + (i - r);
        // dp[i] = a[i] * i + sum - n * i + i;
    }
    ll ss = 0;
    for (auto &x : dp)
        ss += x;
    cout << ss * 2 << endl;
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}