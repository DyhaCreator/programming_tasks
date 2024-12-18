#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;

const int INF = 1e9 + 7;

int len(ll n) {
    int ans = 0;
    while (n/=2) ans++;
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a = {};
    vector<ll> b = {};
    ll save = n;
    while (n > 0) {
        a.push_back(n % 2);
        n /= 2;
    }
    n = save;
    save = k;
    while (k > 0) {
        b.push_back(k % 2);
        k /= 2;
    }
    k = save;
    if (n == 0 && k != 0) {
        cout << -1 << endl;
        return;
    }
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    if (k == 0)
        for (auto &x : a) b.push_back(0);
    if (b.size() != a.size()) {
        cout << -1 << endl;
        return;
    }
    int found = 0;
    int f = 0;
    if (b.size() > 0 && a[0] == 0 && b[0] == 1) found = 1;
    if (a[0] == 1 && b[0] == 1) f = 1;
    for (int i = 1; i < b.size(); i++) {
        if (a[i] == 0 && b[i] == 1) found = 1;
        if (a[i] == 1 && a[i - 1] == 1 && b[i] == 1 && b[i - 1] == 0) found = 1;
        if (a[i] == 1 && a[i - 1] == 1 && b[i] == 0 && b[i - 1] == 1) found = 1;
        if (a[i] == 1 && b[i] == 1) f = 1;
        if (a[i] == 1 && b[i] == 0 && f == 1) found = 1;
    }
    if (found) {
        cout << -1 << endl;
        return;
    }
    found = 0;
    ll ans = 0;
    ll num = 0;
    for (ll i = 0; i < b.size(); i++) {
        if (a[i] == 0 && b[i] == 0) found = 0;
        if (a[i] == 1 && b[i] == 0 && found == 0) {
            ans = (1LL << i) - num;
            found = 1;
        }
        // cout << ans << endl;
        num += a[i] * (1LL << i);
    }
    cout << n + ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}