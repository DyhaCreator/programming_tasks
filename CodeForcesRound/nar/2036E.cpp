#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<ll>> a(n, vector<ll>(k));
    for (auto &x : a) {
        for (auto &y : x)
            cin >> y;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] = a[i][j] | a[i - 1][j];
        }
    }

    while (q--) {
        int m;
        cin >> m;
        int L = 0;
        int R = n - 1;
        for (int i = 0; i < m; i++) {
            int b, d;
            char c;
            cin >> b >> c >> d;
            b--;
            // cout << b << c << d << endl;
            if (c == '>') {
                int l = 0;
                int r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (a[mid][b] <= d) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                L = max(L, r);
            } else {
                int l = 0;
                int r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (a[mid][b] <= d - 1) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                R = min(R, r - 1);
            }
            // cout << L << " " << R << endl;
        }
        if (L <= R && L != n) {
            cout << L + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}