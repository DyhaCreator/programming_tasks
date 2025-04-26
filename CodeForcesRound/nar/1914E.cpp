#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<pair<ll, ll>> d(n);
    for (int i = 0; i < n; i++) {
        d[i].F = b[i] - 1;
        d[i].S = 1 - a[i];
    }
    vector<pair<ll, ll>> s(n);
    for (int i = 0; i < n; i++)
        s[i] = {d[i].F - d[i].S, i};
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    ll sum = 0;
    for (auto &x : a)
        sum += x;
    for (auto &x : b)
        sum -= x;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += d[s[i].S].F;
        } else {
            sum += d[s[i].S].S;
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