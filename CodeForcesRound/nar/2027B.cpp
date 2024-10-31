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
    int ans = INF;
    for (int start = 0; start < n; start++) {
        vector<int> b = {};
        for (int i = start; i < n; i++)
            if (a[i] <= a[start]) b.push_back(a[i]);
        ans = min(ans, int(a.size() - b.size()));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}