#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int sum = 0;
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < min(n, k); i++) {
        sum += a[i];
        mx = max(mx, b[i]);
        ans = max(ans, sum + mx * (k - i - 1));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}