#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll f(ll m, vector<ll>a) {
    ll ans = 0;
    for (auto x : a) {
        ans += std::max(m - x, 0LL);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<ll>a = vector<ll>(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        ll l = 0;
        ll r = k + a.back() + 1;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            // cout << m << " " << f(m, a) << endl;
            if (f(m, a) <= k) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << l << endl;
    }
    return 0;
}