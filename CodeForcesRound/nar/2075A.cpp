#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        cout << (n + k - 2) / (k - 1) << endl;
    } else {
        cout << (n - k + (k - 1) - 1) / (k - 1) + 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}