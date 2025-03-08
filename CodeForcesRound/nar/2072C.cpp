#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int ll = 0;
    vector<int> ans = {};
    for (int i = 0; i < n; i++) {
        ans.push_back(i & x);
        ll |= (i & x);
    }
    if (ll != x)
        ans[ans.size() - 1] = x;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}