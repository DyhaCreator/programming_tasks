#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> count(31);
    for (auto &x : a) {
        for (int i = 0; i < 31; i++) {
            if ((x & (1 << i)) > 0) {
                count[i]++;
            }
        }
    }
    reverse(count.begin(), count.end());
    for (ll i = 0; i < 31; i++) {
        if (n - count[i] <= k) {
            k -= n - count[i];
            count[i] = n;
        }
    }
    reverse(count.begin(), count.end());
    ll ans = 0;
    for (ll i = 0; i < 31; i++) {
        if (count[i] == n) {
            ans += (1 << i);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}