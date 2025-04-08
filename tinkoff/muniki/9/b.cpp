#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll f(ll n, ll m) {
    ll sum = 0;
    for (ll i = 1; i <= (m + 1) / 2; i++) {
        sum += i;
        if (sum >= n) return i;
    }
    for (ll i = (m + 1) / 2; i < m; i++) {
        sum += m - i;
        if (sum >= n) return m - i;
    }
    return 1;
}

ll f2(ll n, ll m) {
    ll cnt = 0;
    ll sum = 0;
    for (ll i = 1; i <= (m + 1) / 2; i++) {
        cnt++;
        sum += i;
        if (sum >= n) return cnt;
    }
    for (ll i = (m + 1) / 2; i < m; i++) {
        cnt++;
        sum += m - i;
        if (sum >= n) return cnt;
    }
    return n - sum + m;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        ll s;
        cin >> s;
        ll l = 0;
        ll r = n;
        while (l < r) {
            ll m = (l + r) / 2;
            if (f(n, m) <= s) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        /*cout << f(n, r) << endl;
        cout << f2(n, r) << endl;
        cout << r << endl;*/
        if (f(n, r) > s) {
            cout << f2(n, r) + 1 << endl;
        } else {
            cout << f2(n, r) << endl;
        }
    }
    return 0;
}