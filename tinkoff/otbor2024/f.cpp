#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll j = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += a[i];
        while (sum > p + q + r) {
            sum -= a[j];
            j++;
        }
        if (sum == p + q + r) {
            // cout << j << " " << i << endl;
            ll sum_p = 0;
            ll sum_q = 0;
            ll sum_r = 0;
            ll index = j;
            while (sum_p < p) {
                sum_p += a[index];
                index++;
            }
            if (sum_p == p) {
                while (sum_q < q) {
                    sum_q += a[index];
                    index++;
                }
                if (sum_q == q) {
                    while (sum_r < r && index <= i) {
                        sum_r += a[index];
                        index++;
                    }
                    if (sum_r == r) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}