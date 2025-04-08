#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    map<ll, int> mp;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    int L = 1;
    int R = 1;
    ll sum = -INF;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0) {
            mp[a[i]] = i + 1;
        } else if (pref[mp[a[i]] - 1] > pref[i]) {
            mp[a[i]] = i + 1;
        }
        // cout << i << " " << mp[a[i]] - 1 << " " << pref[i + 1] << " " << pref[mp[a[i]] - 1] << endl;
        if (sum < pref[i + 1] - pref[mp[a[i]] - 1]) {
            L = mp[a[i]];
            R = i + 1;
            sum = pref[i + 1] - pref[mp[a[i]] - 1];
        }
    }
    cout << sum << endl;
    cout << L << " " << R << endl;
    return 0;
}