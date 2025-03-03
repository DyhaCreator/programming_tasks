#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<pair<ll, ll>> r(n);
    vector<pair<ll, ll>> c(m);
    ll sum1 = 0;
    for (auto &x : a)
        sum1 += x;
    ll sum2 = 0;
    for (auto &x : b)
        sum2 += x;
    for (int i = 0; i < n; i++)
        r[i] = {sum2 * a[i], i};
    for (int i = 0; i < m; i++)
        c[i] = {sum1 * b[i], i};
    ll sum = 0;
    for (auto &x : r)
        sum += x.F;
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    for (auto &x : r)
        cout << x.F << " ";
    cout << endl;
    for (auto &x : c)
        cout << x.F << " ";
    cout << endl;
    while (q--) {
        ll num;
        cin >> num;
        ll L = 0;
        ll R = n * m;
        while (L < R) {
            ll mid = (L + R) / 2;
            ll f1 = r[mid / m].F;
            ll f2 = c[mid % m].F;
            if (f1 + f2 - a[r[mid / m].S] * b[c[mid % m].S] < sum - num) {
                L = mid + 1;
            } else {
                R = mid;
            }
        }
        ll f1 = r[R / m].F;
        ll f2 = c[R % m].F;
        cout << (f1 + f2 - a[r[R / m].S] * b[c[R % m].S]) << endl;
        cout << R << endl;
    }
    return 0;
}