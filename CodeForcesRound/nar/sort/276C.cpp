#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> d(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        d[l]++;
        d[r]--;
    }
    vector<ll> c(n);
    c[0] = d[0];
    for (int i = 1; i < n; i++)
        c[i] = c[i - 1] + d[i];
    sort(c.begin(), c.end());
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * c[i];
    cout << ans << endl;
    return 0;
}