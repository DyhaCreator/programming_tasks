#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        ll cnt = 0;
        ll r, c, b;
        cin >> r >> c >> b;
        vector <vector <ll>> a(r + 1, vector <ll> (c + 1));
        vector <pair<ll, ll>> p;
        ll x, y;
        for (ll j = 0; j < b; ++j) {
            cin >> x >> y;
            a[x][y] = 1;
            pair <ll, ll> z = make_pair(x, y);
            p.push_back(z);
        }
        for (ll j = 1; j <= r; ++j) {
            for (ll k = 1; k <= c; ++k) {
                a[j][k] = a[j][k] + max(a[j - 1][k], a[j][k - 1]);
            }
        }
        for (ll l = 0; l < b; ++l) {
            vector <vector <ll>> n(r + 1, vector <ll> (c + 1));
            for (ll o = 0; o < b; ++o)  {
                n[p[o].first][p[o].second] = 1;
            }
            n[p[l].first][p[l].second] = 0;
            for (ll j = 1; j <= r; ++j) {
                for (ll k = 1; k <= c; ++k) {
                    n[j][k] = n[j][k] + max(n[j - 1][k], n[j][k - 1]);
                }
            }
            if (n[r][c] < a[r][c]) {
                cnt++;
            }
            n[p[l].first][p[l].second] = 1;
        }
        cout << cnt;
    }
}
