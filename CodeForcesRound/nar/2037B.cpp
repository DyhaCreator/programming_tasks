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
    map<int, int> mp;
    for (auto &x : a)
        mp[x]++;
    for (auto &x : a)
        if ((n - 2) % x == 0 && (((n - 2) / x != x && mp[(n - 2) / x] >= 1) || (n - 2) / x == x && mp[(n - 2) / x] >= 2)) {
            cout << x << " " << (n - 2) / x << endl;
            return;
        }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}