#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    if (k == 1) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll ss = 0;
            if (i == 0) {
                ss = a[0] + a[n - 1];
            } else if (i == n - 1) {
                ss = a[0] + a[n - 1];
            } else {
                ss = a[i] + max(a[0], a[n - 1]);
            }
            sum = max(ss, sum);
        }
        cout << sum << endl;
        return;
    }
    vector<pair<ll, ll>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.rbegin(), b.rend());

    if (b[0].S == 0 || b[0].S == n - 1) {
        ll sum = 0;
        for (int i = 0; i <= k; i++)
            sum += b[i].F;
        cout << sum << endl;
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> l = {};
        vector<ll> r = {};
        for (int j = 0; j < n; j++) {
            if (j < i) {
                l.push_back(a[j]);
            } else if (j > i) {
                r.push_back(a[j]);
            }
        }
        // cout << a[i] << endl;
        sort(l.rbegin(), l.rend());
        sort(r.rbegin(), r.rend());
        /*for (auto &x : l)   
            cout << x << " ";
        cout << endl;
        for (auto &x : r)
            cout << x << " ";
        cout << endl;*/
        if (i == 0) {
            ll sum = a[i];
            for (int j = 0; j < k; j++) {
                sum += r[j];
            }
            ans = max(ans, sum);
            continue;
        } else if (i == n - 1) {
            ll sum = a[i];
            for (int j = 0; j < k; j++) {
                sum += l[j];
            }
            ans = max(ans, sum);
            continue;
        }
        ll sum = a[i] + l[0] + r[0];
        int il = 1;
        int ir = 1;
        int cnt = 2;
        while (cnt < k) {
            if (il < l.size() && ir < r.size()) {
                if (l[il] > r[ir]) {
                    sum += l[il];
                    il++;
                } else {
                    sum += r[ir];
                    ir++;
                }
            } else if (il < l.size()) {
                sum += l[il];
                il++;
            } else if (ir < r.size()) {
                sum += r[ir];
                ir++;
            }
            cnt++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}