#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x : a) {
        for (auto &y : x)
            cin >> y;
    }
    for (auto &b : a) {
        int f = 0;
        for (int y = 0; y < n; y++) {
            for (int x = y + 1; x < n; x++) {
                if ((b[y] | b[x]) != a[y][x]) {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            cout << "YES" << endl;
            for (auto &x : b)
                cout << x << " ";
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}