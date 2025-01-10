#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    double n, d, h;
    cin >> n >> d >> h;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    double ans = d * h / 2;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] < h) {
            ans -= (h - a[i] + a[i - 1]) * (h - a[i] + a[i - 1]) / h * d / 2;
        }
        ans += d * h / 2;
    }
    printf("%.6f\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}