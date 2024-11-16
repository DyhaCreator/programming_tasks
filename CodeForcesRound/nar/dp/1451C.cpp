#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> counta(26);
    vector<int> countb(26);
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        counta[a[i] - 'a']++;
        countb[b[i] - 'a']++;
        if (i >= k) {
            counta[a[i - k] - 'a']--;
            countb[b[i - k] - 'a']--;
        }
        int ca = 0;
        for (auto &x : counta)
            if (x > 0) ca++;
        int cb = 0;
        for (auto &x : countb)
            if (x > 0) cb++;
        if (ca != 1 || cb != 1 || a[i] > b[i])
            continue;
        if (i + 1 >= k) dp[i + 1] = dp[i - k + 1];
    }
    if (dp[n]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}