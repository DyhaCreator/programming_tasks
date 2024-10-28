#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; (1LL << (i - 1)) <= n; i++) {
        ans += ((n - (1LL << (i - 1))) / (1LL << i) + 1) * i;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}