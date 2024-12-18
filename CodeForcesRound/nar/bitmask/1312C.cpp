#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> count(100);
    for (auto &x : a) {
        ll save = x;
        ll index = 0;
        while (x > 0) {
            if (x % k > 1) {
                cout << "NO" << endl;
                return;
            }
            if (x % k > 0) {
                count[index]++;
            }
            x /= k;
            index++;
        }
    }
    for (auto &x : count)
        if (x > 1) {cout << "NO" << endl; return;}
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}