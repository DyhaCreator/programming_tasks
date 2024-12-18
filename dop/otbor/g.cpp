#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> c(n);
    for (auto &x : c)
        cin >> x;
    sort(c.begin(), c.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i] * x;
        x = max(1LL, x - 1);
    }
    cout << ans << endl;
    return 0;
}