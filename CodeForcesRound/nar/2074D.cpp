#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<ll> rd(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : rd)
        cin >> x;
    set<int> st;
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        for (int j = a[i] - rd[i]; j <= a[i] + rd[i]; j++) {
            st.insert(j);
            ll l = 0;
            ll r = 1e6;
            while (l < r) {
                ll m = (l + r) / 2;
                if ((ll)abs(j - a[i]) * (ll)abs(j - a[i]) + m * m <= rd[i] * rd[i]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            mp[j] = max(mp[j], r);
        }
    }
    ll sum = 0;
    for (auto &x : st)
        sum += (ll)mp[x] * 2 - 1;
    cout << sum << endl;
    /*for (auto &x : st)
        cout << x << " ";
    cout << endl;
    for (auto &x : st)
        cout << mp[x] << " ";
    cout << endl;*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}