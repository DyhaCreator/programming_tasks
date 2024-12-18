#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> f(50);
    for (int i = 0; i < 50; i++) {
        f[i] = ((n & (1 << i)) >> i);
    }
    ll i = 0;
    while (!(f[i] == 1 && f[i + 1] == 0)) {
        i++;
    }
    // cout << i << endl;
    f[i + 1] = 1;
    f[i] = 0;
    ll ans = 0;
    ll a = 1;
    for (auto &x : f) {
        ans += x * a;
        a = a << 1;
    }
    cout << ans << endl;
    return 0;
}