#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll f(ll n) {
    ll len = 0;
    while (n > 0) {
        n /= 2;
        len++;
    }
    return len;
}

ll f2(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    ll len = f(n);
    int count = f2(n);
    if (count == 1) count--;
    cout << count + 1 << endl;
    for (ll i = len; i >= 0; i--) {
        if ((n & (1LL << i)) >= 1 && (n ^ (1LL << i)) > 0) {
            cout << (n ^ (1LL << i)) << " ";
        }
    }
    cout << n << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}