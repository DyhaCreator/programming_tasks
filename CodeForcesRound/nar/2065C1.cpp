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
    reverse(a.begin(), a.end());
    if (a[0] < b[0] - a[0]) a[0] = b[0] - a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1] || (a[i] < b[0] - a[i] && b[0] - a[i] <= a[i - 1]))
            a[i] = b[0] - a[i];
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