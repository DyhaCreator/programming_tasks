#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    vector<ll> d(n + 1);
    for (int i = 0; i < n; i++)
        d[i + 1] = -d[i] + a[i];
    map<ll, ll> mp0;
    map<ll, ll> mp1;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            ans += mp0[d[i]];
            ans += mp1[-d[i]];
            mp0[d[i]]++;
        } else {
            ans += mp1[d[i]];
            ans += mp0[-d[i]];
            mp1[d[i]]++;
        }
    }
    cout << ans << endl;
    return 0;
}