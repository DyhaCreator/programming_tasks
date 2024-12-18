#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll>map = vector<ll>(n);
    for (auto &x : map)
        cin >> x;
    /*vector<int>a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = map[i - 1] + a[i - 1];
    }*/
    for (int i = 0; i < m; i++) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll x;
            cin >> x;
            map[x - 1]++;
        } else {
            ll l, r;
            cin >> l >> r;
            ll sum = 0;
            for (int i = l - 1; i < r; i++) {
                sum += map[i];
            }
            cout << sum << endl;
        }
    }
    return 0;
}