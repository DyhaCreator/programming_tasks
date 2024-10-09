#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll f(ll n, ll co) {
    ll ans = 0;
    int a = 0;
    while (n > 0) {
        if (a == 0) {
            ans += n % 10;
        } else {
            ans -= n % 10;
        }
        n /= 10;
        a = (a + 1) % 2;
    }
    if (co % 2 == 1) return ans;
    return -ans;
}

ll f2(ll n) {
    int ans = 0;
    while (n > 0) {
        n /= 10;
        ans++;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    int a = 0;
    ll c = 0;
    for (int i = 1; i <= n; i++) {
        ll count = f2(i);
        ll ans = f(i, count);
        if (a == 0) {
            c += ans;
        } else {
            c -= ans;
        }
        cout << i << " " << c << endl;
        // cout << a << " " << ans << " ";
        a = (a + count) % 2;
    }
    cout << c << endl;
    return 0;
}