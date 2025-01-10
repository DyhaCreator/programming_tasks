#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a = {};
    vector<ll> b = {};
    for (int i = 0; i < n * 2; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 0) {
            a.push_back(abs(r));
        } else {
            b.push_back(abs(l));
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += sqrt(a[i] * a[i] + b[i] * b[i]);
    printf("%.9f\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}