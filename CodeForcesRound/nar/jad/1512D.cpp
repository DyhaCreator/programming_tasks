#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 2);
    for (auto &x : a)
        cin >> x;
    map<ll, ll> mp;
    for (auto &x : a)
        mp[x]++;
    ll sum = 0;
    for (auto &x : a) sum += x;
    for (auto &x : a) {
        if ((mp[sum - x * 2] > 0 && sum - x * 2 != x) || (mp[sum - x * 2] > 1 && sum - x * 2 == x)) {
            int f = 0;
            int f1 = 0;
            for (auto &y : a) {
                if (y == x && f1 == 0) {
                    f1 = 1;
                } else if (y == sum - x * 2 && f == 0) {
                    f = 1;
                } else {
                    cout << y << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}