#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m, s;
    cin >> n >> m >> s;
    ll max_ans = 0;
    for (ll i = 1; i <= 100; i++) {
        ll j = s / i;
        if (s == i * j) {
            ll ans = (n / i) * (m / j);
            if (ans > max_ans) {
                max_ans = ans;
            }
        }
    }
    cout << max_ans << endl;
    return 0;
}