#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

map<pair<int, int>, int> mp;

void solve() {
    int l, r;
    cin >> l >> r;
    if (mp[{l, r}] != 0) {
        cout << mp[{l, r}] << endl;
        return;
    }
    int x = l, ans = 0;
    while (x <= r) {
        ans++;
        x += ans;
    }
    mp[{l, r}] = ans;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}