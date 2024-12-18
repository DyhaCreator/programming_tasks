#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll a1, b1, c1;
    ll a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    ll n;
    cin >> n;
    vector<ll> l(n);
    ll yl = 0;
    for (auto &x : l) {
        cin >> x;
        yl += x;
    }
    a2 += c2 * yl;
    for (ll i = 0; i < b2 - 1; i++) {
        a2 += l[i];
    }
    a1 += c1 * yl;
    for (ll i = 0; i < b1 - 1; i++) {
        a1 += l[i];
    }
    cout << a2 - a1 + 1 << endl;
    return 0;
}