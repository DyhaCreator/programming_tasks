#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    ll l = 0;
    ll r = 0;
    ll st = 1;
    ll ans = INF;
    for (int i = 0; i < 10; i++) {
        l *= 10;
        l += 9;
        
        ll a = n;
        ll cnt = 0;
        while ((a / st) % 10 != 7 && cnt < 20) {
            a += l;
            cnt++;
        }
        ans = min(ans, cnt);
        cnt = 0;
        a = n;
        while ((a / st) % 10 != 7 && cnt < 20) {
            a += r;
            cnt++;
        }
        ans = min(ans, cnt);

        r *= 10;
        r += 9;
        st *= 10;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}