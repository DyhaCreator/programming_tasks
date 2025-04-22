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
    int mx = 0;
    for (auto &x : a)
        mx = max(mx, x);
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) index = i;
    }
    vector<int> ans(n);
    int l = 1;
    int r = n;
    for (int i = 1; i <= mx; i++) {
        vector<int> li = {};
        vector<int> ri = {};
        for (int j = 0; j < n; j++) {
            if (a[j] == i) {
                if (j < index) {
                    li.push_back(j);
                } else {
                    ri.push_back(j);
                }
            }
        }
        reverse(ri.begin(), ri.end());
        for (auto &x : li) {
            if (i % 2 == 1) {
                ans[x] = r;
                r--;
            } else {
                ans[x] = l;
                l++;
            }
        }
        for (auto &x : ri) {
            if (i % 2 == 1) {
                ans[x] = r;
                r--;
            } else {
                ans[x] = l;
                l++;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        if (a[j] == -1) {
            ans[j] = l;
        }
    }
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}