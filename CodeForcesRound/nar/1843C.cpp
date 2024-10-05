#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    ll save_n = n;
    vector<int> a = {};
    while (n > 0) {
        a.push_back(n % 2);
        n /= 2;
    }
    n = save_n;
    ll ans = 0;
    ll num = 0;
    reverse(a.begin(), a.end());
    for (auto &x : a) {
        num = (num << 1) + x;
        ans += num;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}