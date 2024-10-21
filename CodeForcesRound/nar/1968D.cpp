#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k, pa, pb;
    cin >> n >> k >> pa >> pb;
    vector<ll> p(n);
    vector<ll> a(n);
    for (auto &x : p)
        cin >> x;
    for (auto &x : a)
        cin >> x;
    ll an1, an2;
    ll ans = a[pa - 1] * k;
    // cout << ans << endl;
    ll len = 0;
    ll index = p[pa - 1] - 1;
    ll sum = a[pa - 1];
    while (index != pa - 1 && len + 1 < k) {
        len++;
        sum += a[index];
        ll res = sum + a[index] * (k - len - 1);
        ans = max(ans, res);
        // cout << a[index] << " " << sum << " " << len << " " << res << endl;
        index = p[index] - 1;
    }
    // cout << ans << endl;
    an1 = ans;
    pa = pb;

    ans = a[pa - 1] * k;
    // cout << ans << endl;
    len = 0;
    index = p[pa - 1] - 1;
    sum = a[pa - 1];
    while (index != pa - 1 && len + 1 < k) {
        len++;
        sum += a[index];
        ll res = sum + a[index] * (k - len - 1);
        ans = max(ans, res);
        // cout << a[index] << " " << sum << " " << len << " " << res << endl;
        index = p[index] - 1;
    }
    // cout << ans << endl;
    an2 = ans;
    // cout << an1 << " " << an2 << endl;
    if (an1 > an2) {
        cout << "Bodya\n";
    } else if (an2 > an1) {
        cout << "Sasha\n";
    } else {
        cout << "Draw\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}