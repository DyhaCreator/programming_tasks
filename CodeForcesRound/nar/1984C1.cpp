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
    vector<ll> dp1(n);
    vector<ll> dp2(n);
    dp1[0] = a[0];
    dp2[0] = abs(a[0]);
    for (int i = 1; i < n; i++) {
        ll c1 = dp1[i - 1] + a[i];
        ll c2 = abs(dp1[i - 1] + a[i]);
        ll c3 = dp2[i - 1] + a[i];
        ll c4 = abs(dp2[i - 1] + a[i]);
        dp1[i] = min(min(c1, c2), min(c3, c4));
        dp2[i] = max(max(c1, c2), max(c3, c4));
    }
    /*for (auto &x : dp1)
        cout << x << " ";
    cout << endl;
    for (auto &x : dp2)
        cout << x << " ";
    cout << endl;*/
    cout << max(abs(dp1[n - 1]), abs(dp2[n - 1])) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}