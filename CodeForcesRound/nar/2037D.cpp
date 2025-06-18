#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, m, L;
    cin >> n >> m >> L;
    vector<pair<ll, ll>> p(n);
    for (auto &x : p)
        cin >> x.F >> x.S;
    vector<ll> w(m);
    vector<ll> v(m);
    for (int i = 0; i < m; i++)
        cin >> w[i] >> v[i];
    ll ans = 0;
    ll j = 0;
    ll sum = 1;

    set<pair<ll, ll>> ws = {};
    for (int i = 0; i < n; i++) {
        while (w[j] <= p[i].F && j < m) {
            ws.insert({v[j], j});
            j++;
        }
        while (sum < p[i].S - p[i].F + 2 && ws.size() > 0) {
            sum += ws.rbegin()->F;
            ws.erase(*ws.rbegin());
            ans++;
            // cout << sum << " " << ws.size() << endl;
        }
        if (sum < p[i].S - p[i].F + 2) {
            cout << -1 << endl;
            return ;
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