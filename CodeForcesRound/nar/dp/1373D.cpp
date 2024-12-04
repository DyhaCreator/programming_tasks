#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> l(n + 1);
    vector<ll> r(n + 1);
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i];
        r[i + 1] = r[i];
        if (i % 2 == 0) {
            l[i + 1] += a[i];
        } else {
            r[i + 1] += a[i];
        }
    }
    vector<ll> dp(n);
    int mxL = 0;
    int mxR = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            if (l[i] - r[i] > l[mxL] - r[mxL]) {
                mxL = i;
            }
            dp[i - 1] = r[i] - r[mxL] + l[mxL] + l[n] - l[i];
        } else {
            if (l[i] - r[i] > l[mxR] - r[mxR]) {
                mxR = i;
            }
            dp[i - 1] = r[i] - r[mxR] + l[mxR] + l[n] - l[i];
        }
    }
    ll ans = a[0];
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    /*cout << mxL << " " << mxR << endl;
    for (auto &x : l)
        cout << x << " ";
    cout << endl;
    for (auto &x : r)
        cout << x << " ";
    cout << endl;
    for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}