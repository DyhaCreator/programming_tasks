#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (k > 1) {
        cout << "YES" << endl;
    } else {
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}