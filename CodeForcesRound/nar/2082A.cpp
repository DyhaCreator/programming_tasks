#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    int cnty = 0;
    int cntx = 0;
    for (int y = 0; y < n; y++) {
        int sum = 0;
        for (auto &x : a[y])
            sum += x - '0';
        if (sum % 2 == 1) {
            cnty++;
        }
    }
    for (int x = 0; x < m; x++) {
        int sum = 0;
        for (int y = 0; y < n; y++) {
            sum += a[y][x];
        }
        if (sum % 2 == 1) {
            cntx++;
        }
    }
    
    cout << max(cnty, cntx) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}