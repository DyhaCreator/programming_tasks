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
    for (auto &x : a)
        cin >> x;
    if (m < n || n == 2) {
        cout << -1 << endl;
        return;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
        c += a[i] + a[(i + 1) % n];
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    cout << c + (a[0] + a[1]) * (m - n) << endl;
    for (int i = 0; i < n; i++)
        cout << i + 1 << " " << (i + 1) % n + 1 << endl;
    for (int i = n; i < m; i++)
        cout << b[0].second + 1 << " " << b[1].second + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}