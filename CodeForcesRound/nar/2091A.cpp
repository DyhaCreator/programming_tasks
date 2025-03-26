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
    vector<int> b = {0, 1, 0, 3, 2, 0, 2, 5};
    vector<int> cnt(10);
    for (auto &x : b)
        cnt[x]++;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]--;
        int c = 0;
        for (auto &y : cnt) {
            c += max(y, 0);
        }
        if (c == 0) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}