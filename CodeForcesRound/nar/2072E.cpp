#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans = {};
    int sum = 0;
    while (sum < n) {
        int l = 1;
        int r = 500;
        while (l < r) {
            int m = (l + r) / 2;
            if (m * (m - 1) / 2 < n - sum) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (r * (r - 1) / 2 + sum > n) r--;
        ans.push_back(r);
        sum += r * (r - 1) / 2;
    }
    sum = 0;
    for (auto &x : ans)
        sum += x;
    cout << sum << endl;
    int x = 0;
    for (int y = 0; y < ans.size(); y++) {
        for (int i = 0; i < ans[y]; i++) {
            cout << y << " " << x << endl;
            x++;
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}