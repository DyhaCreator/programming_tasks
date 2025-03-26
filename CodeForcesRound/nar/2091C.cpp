#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> a = {};
    for (int i = 1; i <= n; i+=2) {
        a.push_back(i);
    }
    for (int i = 2; i <= n; i+=2) {
        a.push_back(i);
    }
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}