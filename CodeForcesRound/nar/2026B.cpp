#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1000000000000000000 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(n);
    vector<ll> c(n);
    b[0] = INF;
    c[n - 1] = INF;
    for (int i = 1; i < n; i++)
        b[i] = a[i] - a[i - 1];
    for (int i = 0; i < n - 1; i++)
        c[i] = a[i + 1] - a[i];
    int mxi = 0;
    for (int i = 0; i < n; i++) {
        if (min(b[i], c[i]) > min(b[mxi], c[mxi])) {
            mxi = i;
        }
    }
    if (b[mxi] != INF) {
        b[mxi] = 1;
    } else {
        c[mxi] = 1;
    }
    if (mxi > 0 && mxi < n - 1) {
        if (b[mxi + 1] > c[mxi - 1]) {
            b[mxi + 1]--;
        } else {
            c[mxi - 1]--;
        }
    } else {
        if (mxi > 0) {
            c[mxi - 1]--;
        } else {
            b[mxi + 1]--;
        }
    }
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, min(b[i], c[i]));
    }
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}