#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int secmin(int a, int b, int c) {
    if ((a > b && a < c) || (a < b && a > c))
        return a;
    if ((b > a && b < c) || (b > c && b < a))
        return b;
    return c;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int mx = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1] || (i < n - 2 && a[i] == a[i + 2])) {
            mx = max(mx, a[i]);
        }
    }
    if (mx == 0) {
        for (int i = 0; i < n - 2; i++) {
            // cout << secmin(a[i], a[i + 1], a[i + 2]) << endl;
            mx = max(secmin(a[i], a[i + 1], a[i + 2]), mx);
        }
        if (n == 2) {
            mx = max(mx, min(a[0], a[1]));
        }
    }
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}