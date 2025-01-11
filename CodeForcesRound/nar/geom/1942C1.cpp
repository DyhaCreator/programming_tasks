#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, l;
    cin >> m >> n >> l;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = n - 2;
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] == 2) ans++;
    if (a[0] - (a[n - 1] - m) == 2) ans++;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}