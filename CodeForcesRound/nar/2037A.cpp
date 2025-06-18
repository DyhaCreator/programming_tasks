#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    int ans = 0;
    for (auto &x : cnt)
        ans += x / 2;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}