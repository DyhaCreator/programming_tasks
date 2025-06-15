#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int st = 1;

ll fmn(vector<ll> &d, ll l, ll r) {
    ll ans = INF;
    ll L = st + l;
    ll R = st + r;
    ans = min(d[L], d[R]);
    while (L <= R) {
        if (L % 2 == 1) ans = min(d[L], ans);
        if (R % 2 == 0) ans = min(d[R], ans);
        R = (R - 1) / 2;
        L = (L + 1) / 2;
    }
    return ans;
}

ll fmx(vector<ll> &d, ll l, ll r) {
    ll ans = 0;
    ll L = st + l;
    ll R = st + r;
    ans = max(d[L], d[R]);
    while (L <= R) {
        if (L % 2 == 1) ans = max(d[L], ans);
        if (R % 2 == 0) ans = max(d[R], ans);
        R = (R - 1) / 2;
        L = (L + 1) / 2;
    }
    return ans;
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<ll> al(n);
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
        cin >> al[i] >> ar[i];
    while (st < n)
        st *= 2;
    vector<ll> dl(st * 2);
    vector<ll> dr(st * 2);
    for (int i = 0; i < n; i++) {
        dl[st + i] = al[i];
        dr[st + i] = ar[i];
    }
    for (int i = st - 1; i > 0; i--) {
        dl[i] = max(dl[i * 2], dl[i * 2 + 1]);
        dr[i] = min(dr[i * 2], dr[i * 2 + 1]);
    }
    /*for (auto &x : dl)
        cout << x << " ";
    cout << endl;
    for (auto &x : dr)
        cout << x << " ";
    cout << endl;*/
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] - al[i] < m1)
            continue;
        ll l = i;
        ll r = n;
        while (l < r) {
            ll m = (l + r) / 2;
            if (max(fmn(dr, i, m) - fmx(dl, i, m), 0LL) > m2) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ll L = r;
        l = L;
        r = n;
        while (l < r) {
            ll m = (l + r) / 2;
            if (max(fmn(dr, i, m) - fmx(dl, i, m), 0LL) >= m1) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        sum += (ll)r - (ll)L;
        // cout << L << " " << r << endl;
    }
    cout << sum << endl;
    return 0;
}