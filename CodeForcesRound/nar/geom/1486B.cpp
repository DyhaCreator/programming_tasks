#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto &x : a)
        cin >> x.S >> x.F;
    ll minY = INF;
    ll maxY = 0;
    ll minX = INF;
    ll maxX = 0;
    for (auto &x : a) {
        int l = 0;
        int th = 0;
        int r = 0;
        for (auto &y : a) {
            if (y.F < x.F) {
                l++;
            } else if (y.F > x.F) {
                r++;
            } else {
                th++;
            }
        }
        if (abs(l - r) <= th) {
            minY = min(minY, x.F);
            maxY = max(maxY, x.F);
        }
        th = 0;
        l = 0;
        r = 0;
        for (auto &y : a) {
            if (y.S < x.S) {
                l++;
            } else if (y.S > x.S) {
                r++;
            } else {
                th++;
            }
        }
        if (abs(l - r) <= th) {
            minX = min(minX, x.S);
            maxX = max(maxX, x.S);
        }
    }
    cout << (maxY - minY + 1) * (maxX - minX + 1) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}