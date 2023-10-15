#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll>pref = vector<ll>();
    pref.push_back(0);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pref.push_back(pref.back() + x);
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " ";
    }
    return 0;
}