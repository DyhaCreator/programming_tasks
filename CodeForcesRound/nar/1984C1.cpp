#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = 0;
    for (auto &x : a) {
        if (x > 0) {
            ans = abs(ans) + x;
        } else {
            ans += x;
        }
        cout << ans << ' ';
    }
    cout << abs(ans) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}