#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, r;
    cin >> n >> r;
    vector<ll>a(n);
    ll last = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x - last;
        last = x;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    ll ans = 0;

    ll curSum = 0;
    for (ll l = 0, r = 0; r < n; r++) {

        curSum += a[r];

        while (curSum > r) {
            curSum -= a[l];
            l++;
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}