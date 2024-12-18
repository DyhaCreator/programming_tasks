#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(q);
    for (auto &x : b)
        cin >> x;
    vector<ll> cols(n + 1);
    ll count = 0;
    for (int i = 0; i < n; i++) {
        count += n - i - 1;
        cols[i] = count;
        // cout << cols[i] << " ";
        count -= i;
    }
    // cout << endl;
    map<ll, ll> ans;
    count = 0;
    for (int i = 0; i < n; i++) {
        ans[cols[i]] += 1;
        if (i < n - 1) ans[cols[i] - i] += a[i + 1] - a[i] - 1;
        // cout << ans[cols[i]] << " ";
    }
    // cout << endl;
    // cout << endl;
    for (auto &x : b)
        cout << ans[x] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}