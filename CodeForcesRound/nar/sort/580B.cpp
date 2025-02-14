#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    sort(a.begin(), a.end());
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i].S;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m].F - a[i].F < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans = max(ans, pref[r] - pref[i]);
    }
    cout << ans << endl;
    return 0;
}