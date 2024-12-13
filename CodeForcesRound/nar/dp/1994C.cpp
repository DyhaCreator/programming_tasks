#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    vector<ll> pref_dp(n + 1);
    vector<ll> dp(n);
    int L = 0;
    int R = 0;
    for (int i = 0; i < n; i++) {
        while (L < i && pref[i] - pref[L] > x) L++;
        while (R <= i && pref[i + 1] - pref[R] > x) {
            R++;
        }
        cout << L << " " << R << endl;
        pref_dp[i + 1] = pref_dp[i];
        if (pref[i] - pref[L] + a[i] > x) {
            cout << L << " " << R << endl;
            dp[i] = pref_dp[R] - pref_dp[max(L - 1, 0)] + (R - L);
            pref_dp[i + 1] += dp[i];
        }
    }
    cout << endl;
    for (auto &x : pref_dp)
        cout << x << " ";
    cout << endl;
    for (auto &x : dp)
        cout << x << " ";
    cout << endl;

    ll ans = 0;
    for (auto &x : dp)
        ans += x;
    cout << (n * (n + 1)) / 2 - ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}