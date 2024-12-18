#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    ll a = 0;
    ll b = 1;
    ll bi = 0;
    for (ll i = 2; b <= n; i++) {b *= i;bi = i;}
    while ((1LL << a) <= n) a++;
    b /= bi;
    bi--;a--;
    cout << (1LL << a) << " " << a << " " << b << " " << bi << endl;
    int ans = 0;
    while (n > 0) {
        while (n < (1LL << a)) a--;
        while (n < b) {b /= bi; bi--;}
        cout << (1LL << a) << " " << b << " " << (n & (1LL << a)) << " " << (n & b) << endl;
        if ((n & (1LL << a)) < (n & b) && bi > 0) {
            n -= b;
            b /= bi;
            bi--;
        } else {
            n -= (1LL << a);
            a--;
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}