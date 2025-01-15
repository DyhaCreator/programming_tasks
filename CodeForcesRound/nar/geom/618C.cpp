#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll dst2(pair<ll, ll> &a, pair<ll, ll> &b) {
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}
double dst(pair<ll, ll> &a, pair<ll, ll> &b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    int mn = 1;
    for (int i = 1; i < n; i++)
        if (dst2(a[0], a[i]) < dst2(a[0], a[mn])) mn = i;
    pair<ll, ll> cnt = {(a[0].F + a[mn].F) / 2.0, (a[0].S + a[mn].S) / 2.0};
    int mn2 = -1;
    for (int i = 1; i < n; i++) {
        ll x1 = a[0].F - a[i].F;
        ll y1 = a[0].S - a[i].S;
        ll x2 = a[0].F - a[mn].F;
        ll y2 = a[0].S - a[mn].S;
        ll sc = x1 * y2 - y1 * x2;
        if (i != mn && ((mn2 == -1 || dst2(cnt, a[i]) < dst2(cnt, a[mn2])) && sc != 0))
            mn2 = i;
    }
    if (mn2 == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << " " << mn + 1 << " " << mn2 + 1 << endl;
    return 0;
}