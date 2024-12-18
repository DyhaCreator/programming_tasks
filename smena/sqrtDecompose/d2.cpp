#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

const ll INF = 1e10 + 7;
const int len = 256;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> dec(n / len + 1, -INF);
    vector<ll> add(n / len + 1, 0);
    for (int i = 0; i < n; i++)
        dec[i / len] = max(a[i], dec[i / len]);
    int m;
    cin >> m;
    for (int q = 0; q < m; q++) {
        char ch;
        cin >> ch;
        int l, r;
        cin >> l >> r;
        l--;r--;
        if (ch == 'm') {
            ll ans = 0;
            for (int i = l; i <= r;) {
                if (i % len == 0 && i + len <= r) {
                    ans = max(dec[i / len], ans);
                    i += len;
                } else {
                    ans = max(ans, a[i] + add[i / len]);
                    // cout << a[i] + add[i / len] + add_one[i] << endl;
                    i++;
                }
                // cout << i << endl;
            }
            cout << ans << endl;
        } else {
            int x;
            cin >> x;
            for (int i = l; i <= r;) {
                if (i % len == 0 && i + len <= r) {
                    dec[i / len] += x;
                    add[i / len] += x;
                    i += len;
                } else {
                    a[i] += x;
                    dec[i / len] = max(dec[i / len], a[i] + add[i / len]);
                    i++;
                }
            }
        }
    }
    return 0;
}