#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<int> d(n - 1);
    for (int i = 1; i < n; i++) {
        d[i - 1] = a[i] - a[i - 1];
    }
    int mx = 0;
    for (int i = 0; i < n - 2; i++) {
        mx = max(mx, a[n - 1] - a[i] + d[i]);
    }
    for (int i = 2; i < n; i++) {
        mx = max(mx, a[i] - a[0] + d[i - 1]);
    }
    cout << mx << endl;
    /*for (auto &x : d)
        cout << x << " ";
    cout << endl;*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}