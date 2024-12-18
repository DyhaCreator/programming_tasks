#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll count(vector<ll> &a, ll index) {
    ll ans = 0;
    for (auto &x : a)
        if (x - index > 0) ans += x - index;
    return ans;
}

int main() {
    ll m, n;
    cin >> m >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    a.push_back(0);
    sort(a.rbegin(), a.rend());
    // vector<int> save_a = a;
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    ll l = 0;
    ll r = a[0];
    while (l < r) {
        ll mid = (l + r) / 2;
        // cout << count(a, mid) << " " << l << " " << r << endl;
        if (count(a, mid) > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    // cout << count(a, l) << " " << l << " " << r << endl;
    for (auto &x : a) {
        if (x - l > 0) m -= x - l;
        x = min(x, l);
    }
    /*cout << m << endl;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    for (auto &x : a) {
        if (m > 0) {
            x--;
            m--;
        }
    }
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] * a[i]);
    }
    cout << ans << endl;
    return 0;
}