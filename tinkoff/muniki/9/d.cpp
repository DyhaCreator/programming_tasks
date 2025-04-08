#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll sum = pref[n];
        sum -= pref[min(i + k + 1, n)] - pref[max(i - k, 0)];
        sum += a[i] * (min(i + k + 1, n) - max(i - k, 0));
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}