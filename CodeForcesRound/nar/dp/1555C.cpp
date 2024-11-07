#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));
    for (auto &x : a)
        cin >> x[0];
    for (auto &x : a)
        cin >> x[1];
    vector<ll> pref1(n + 1);
    vector<ll> pref2(n + 1);
    for (int i = n - 1; i >= 0; i--)
        pref1[i] = pref1[i + 1] + a[i][0];
    for (int i = 0; i < n; i++)
        pref2[i + 1] = pref2[i] + a[i][1];
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, max(pref2[i], pref1[i + 1]));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}