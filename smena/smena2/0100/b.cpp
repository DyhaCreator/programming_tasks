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
    int null = 0;
    for (auto &x : a)
        if (x != a[0]) null = 1;
    if (null == 0) {
        cout << 0 << endl;
        return;
    }
    int p = -1;
    int m = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1] && p == -1)
            p = a[i] - a[i - 1];
        if (a[i] < a[i - 1] && m == 1)
            m = a[i] - a[i - 1];
        if (a[i] - a[i - 1] != m && a[i] - a[i - 1] != p) {
            cout << -1 << endl;
            return;
        }
    }
    int mod = p - m;
    int f = 0;
    if (m == 1) {
        cout << 0 << endl;
        return;
    }
    if (p == -1) {
        cout << 0 << endl;
        return;
    }
    for (auto &x : a)
        if (x >= mod) f = 1;
    if (f == 1) {
        cout << -1 << endl;
        return;
    }
    cout << mod << " " << p << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}