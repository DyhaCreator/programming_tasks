#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> d(q);
    for (auto &x : d)
        cin >> x;
    for (int i = 2; i <= n; i++)
        cout << i - 1 << " " << i << endl;
    int last = n - 1;
    for (auto &x : d) {
        if (x == last) {
            cout << -1 << " " << -1 << " " << -1 << endl;
        } else {
            cout << n << " " << last << " " << x << endl;
            last = x;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}