#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll p(ll n) {
    ll st = 1;
    while (n--)
        st *= 10;
    return st;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(n);
    b[n - 1] = INF;
    for (int i = 0; i < n - 1; i++)
        b[i] = p(a[i + 1] - a[i]) - 1;

    vector<ll> c = {};
    k++;
    int i = 0;
    while (k > 0) {
        c.push_back(min(k, b[i]));
        k -= min(k, b[i]);
        i++;
    }
    reverse(c.begin(), c.end());
    for (auto &x : c)
        cout << x;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}