#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll f(vector<ll> &a, ll m) {
    cout << m << endl;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    ll th = 0;
    ll ans = 0;
    for (ll &x : a) {
        ans += th - x;
        cout << th << " ";
        th += m;
    }
    cout << endl;
    cout << ans << endl;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    int l = 1;
    int r = 100;
    while (l < r) {
        int m = (l + r) / 2;
        // cout << l << " " << r << endl;
        if (f(a, m) <= 0) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    if (f(a, r) < f(a, r - 1)) {
        cout << abs(f(a, r)) << endl;
    } else {
        cout << abs(f(a, r - 1)) << endl;
    }
    // cout << r << endl;
    return 0;
}