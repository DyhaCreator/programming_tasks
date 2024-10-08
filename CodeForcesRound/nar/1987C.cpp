#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    int last = 0;
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (last < a[i - 1]) {
            mx = max(mx, a[i - 1]);
        } else {
            cout << mx << " ";
            ans += mx - a[i - 1] + 1;
            mx = a[i - 1];
        }
        last = a[i - 1];
    }
    ans += mx - a[n - 1] + 1;
    cout << mx << " ";
    cout << endl;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}