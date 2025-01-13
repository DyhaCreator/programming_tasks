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
        int u = 0;
        int d = 0;
        for (auto &y : a) {
            if (y.F > x.F) {
                u++;
            } else if (y.F < x.F) {
                d++;
            }
        }
        if (abs(u - d) <= 1 || abs(max(u, d) - (n - max(u, d))) <= 1) {
            minY = min(minY, x.F);
            maxY = max(maxY, x.F);
        }
        u = 0;
        d = 0;
        for (auto &y : a) {
            if (y.S > x.F) {
                u++;
            } else {
                d++;
            }
        }
        if (abs(u - d) <= 1 || abs(max(u, d) - (n - max(u, d))) <= 1) {
            minX = min(minX, x.S);
            maxX = max(maxX, x.S);
        }
    }
    cout << minY << " " << maxY << "  " << minX << " " << maxX << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}