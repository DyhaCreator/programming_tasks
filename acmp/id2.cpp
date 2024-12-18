#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    if (n > 0) {
        for (ll i = 1; i <= n; i++) {
            ans += i;
        }
    } else {
        for (ll i = 1; i >= n; i--) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}