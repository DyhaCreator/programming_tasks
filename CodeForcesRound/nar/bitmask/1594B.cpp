#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll aaa = 1;
    for (ll i = 0; i < 32; i++) {
        if ((k & (1LL << i)) > 0) {
            ans += aaa;
            ans = ans % INF;
        }
        aaa *= n;
        aaa = aaa % INF;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}