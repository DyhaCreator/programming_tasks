#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cnt1 += a[i] - '0';
            cnt2 += b[i] - '0';
        } else {
            cnt1 += b[i] - '0';
            cnt2 += a[i] - '0';
        }
    }
    if (cnt1 > n / 2) {
        cout << "NO" << endl;
    } else if (cnt2 > (n + 1) / 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}