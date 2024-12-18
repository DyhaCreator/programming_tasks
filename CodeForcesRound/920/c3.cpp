#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll> m(n);
        for (auto &x : m)
            cin >> x;
        vector<ll> r(n);
        r[0] = m[0];
        for (int i = 1; i < n; i++) {
            r[i] = m[i] - m[i - 1];
        }
        ll sum = 0;
        for (auto &x : r) {
            sum += min(b, x * a);
        }
        // cout << sum << endl;
        if (sum < f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}