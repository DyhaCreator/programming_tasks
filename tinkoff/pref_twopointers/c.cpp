#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll>a(n + 1);
    for (ll i = 0; i < q; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        a[l - 1] += d;
        a[r] -= d;
    }
    ll l = 0;
    for (ll i = 0; i < n; i++) {
        l += a[i];
        cout << l << " ";
    }
    cout << endl;
    return 0;
}