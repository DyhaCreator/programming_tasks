#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
        cnt[i + 1] = cnt[i] + (s[i] == '1');
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] <= n - cnt[n] && i - cnt[i] <= cnt[n]) {
            ans = i;
        }
    }
    cout << n - ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}