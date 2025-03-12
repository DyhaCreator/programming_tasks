#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int l = 0;
    int r = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[l] - b[l]) > abs(a[n - r] - b[m - r])) {
            sum += abs(a[l] - b[l]);
            l++;
        } else {
            sum += abs(a[n - r] - b[m - r]);
            r++;
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