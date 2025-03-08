#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int save_n = n;
    int y = 0;
    while ((1 << y) <= n) y++;
    y--;
    vector<int> a = {n};
    while (n != (1 << y)) {
        n -= (1 << y);
        a.push_back(n);
        while ((1 << y) > n)
            y--;
    }
    reverse(a.begin(), a.end());
    vector<int> ans(a[0], 1);
    for (int i = 1; i < a.size(); i++) {
        vector<int> b = ans;
        while (ans.size() < a[i] - b.size()) ans.push_back(0);
        for (auto &x : b)
            ans.push_back(x);
    }
    for (auto &x : ans)
        if (x == 1) cout << k << " ";
        else cout << 0 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}