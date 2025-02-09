#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(b.rbegin(), b.rend());
    reverse(a.begin(), a.end());
    for (auto &x : b)
        a[0] = max(a[0], x - a[0]);
    for (int i = 1; i < n; i++) {
        int l = 0;
        int r = m - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (b[m] - a[i] > a[i - 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << b[r] - a[i] << endl;
        if (a[i] > a[i - 1] || (b[r] - a[i] > a[i] && b[r] - a[i] <= a[i - 1]))
            a[i] = b[r] - a[i];
        if (a[i] > a[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}