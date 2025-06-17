#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], c[i]};
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = b[i].F;
        c[i] = b[i].S;
    }
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    for (auto &x : c)
        cout << x << " ";
    cout << endl;
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, a[i] * min(c[i], m / a[i]));
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] == 1) {
            if (a[i] * c[i] < m) {
                if (a[i] * c[i] + a[i + 1] * c[i + 1] <= m) {
                    ans = max(ans, a[i] * c[i] + a[i + 1] * c[i + 1]);
                } else {
                    ll ca = a[i] * c[i] + (m - a[i] * c[i]) / a[i + 1] * a[i + 1];
                    
                }
            }
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