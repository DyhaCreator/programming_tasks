#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x - 1] += y;
    }

    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < min(n, k); i++)
        ans += a[i];
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}