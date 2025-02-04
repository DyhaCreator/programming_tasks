#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> pref(n + 1);
    vector<ll> suff(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; i--)
        suff[i] = suff[i + 1]  + a[i];
    ll sum = 0;
    for (auto &x : a)
        sum += x;
    if (sum % 3 != 0 || n < 3) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 3;
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (suff[i] == sum)
            ans += cnt;
        if (pref[i] == sum && i != 0)
            cnt++;
    }
    cout << ans << endl;
    return 0;
}