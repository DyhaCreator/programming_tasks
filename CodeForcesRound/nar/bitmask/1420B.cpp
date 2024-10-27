#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(int n) {
    int ans = 0;
    while (n /= 2)
        ans++;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> count(32, 0);
    for (auto &x : a)
        count[f(x)]++;
    ll ans = 0;
    for (auto &x : count)
        ans += (x * (x - 1)) / 2;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}