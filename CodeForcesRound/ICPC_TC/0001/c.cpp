#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    cout << n * (n - 1) * (n - 2) / 6 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}