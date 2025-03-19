#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll r, g, b;
    cin >> r >> g >> b;
    ll ans = 0;
    vector<ll> a = {r, g, b};
    while (max(a[0], max(a[1], a[2])) < a[0] + a[1] + a[2] && a[0] + a[1] + a[2] >= 3) {
        sort(a.rbegin(), a.rend());
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;
        cout << ans << endl;*/
        /*a[0] -= 2;
        a[1] -= 1;
        ans++;*/
        if (a[0] == a[1] && a[1] == a[2]) {
            ans += a[0];
            break;
        }
        if (a[0] == a[1] && a[1] - a[2] == 1) {
            ans += a[2];
            a[0] = 1;
            a[1] = 1;
            a[2] = 0;
        } else if (a[0] == a[1] && a[1] - a[2] > 3) {
            ll diff = (a[1] - a[2]) / 3;
            a[1] = (a[1] - a[2]) % 3 + a[2];
            a[0] = a[1];
            ans += diff * 2;
        } else if (a[0] == a[1]) {
            a[0] -= 2;
            a[1] -= 1;
            ans++;
            continue;
        }
        if (a[1] == a[2] && a[0] - a[1] == 1) {
            ans += a[1];
            a[0] = 1;
            a[1] = 0;
            a[2] = 0;
        } else if (a[1] == a[2]) {
            ll diff = min((a[0] - a[1] + 1) / 2, a[2] * 2);
            a[0] -= diff * 2;
            a[1] -= diff / 2;
            a[2] -= (diff + 1) / 2;
            ans += diff;
            continue;
        }
        ll diff = min(a[0] - a[1], a[1] - a[2]);
        a[0] -= diff * 2;
        a[1] -= diff;
        ans += diff;
    }
    cout << ans << endl;
    return 0;
}