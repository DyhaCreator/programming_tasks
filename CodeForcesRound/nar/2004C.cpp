#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            ll mk = min(k, a[i - 1] - a[i]);
            a[i] += min(k, a[i - 1] - a[i]);
            k -= mk;
        }
    }
    
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += a[i];
        } else {
            sum -= a[i];
        }
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}