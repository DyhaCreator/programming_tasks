#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    sort(a.begin(), a.end());
    vector<ll> prefs(n + 1);
    for (int i = 0; i < n; i++)
        prefs[i + 1] = prefs[i] + a[i];
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            cout << pref[r] - pref[l - 1] << endl;
        } else {
            cout << prefs[r] - prefs[l - 1] << endl;
        }
    }
    return 0;
}