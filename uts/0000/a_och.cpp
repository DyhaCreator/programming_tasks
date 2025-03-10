#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> d(n);
    for (auto &[l, r] : d)
        cin >> l >> r;
    set<pair<ll, ll>> st;

    for (auto &[l, r] : d) {
        for (ll t = l; t <= r; t++) {
            st.insert({(t + (t / b)) % a, t % b});
        }
    }
    cout << st.size() << endl;
    return 0;
}