#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        ans += i * i;
    }
    cout << ans << endl;
    return 0;
}