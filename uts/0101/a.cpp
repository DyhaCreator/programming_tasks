#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x)
            cin >> y;
    }
    int f = 0;
    if (m > n) {
        f = 1;
        vector<vector<int>> b(m, vector<int>(n));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                b[x][y] = a[y][x];
            }
        }
        a = b;
        swap(n, m);
    }
    vector<int> w(n);
    vector<int> h(m);
    for (int y = 0; y < n; y++) {
        for (auto &x : a[y])
            w[y] = max(w[y], x);
    }
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            h[x] = max(h[x], a[y][x]);
        }
    }
    vector<int> cnt(m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] == w[y] && a[y][x] == h[x]) {
                cnt[x]++;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int r, c, k;
        cin >> r >> c >> k;
        r--;c--;
        if (f) {
            swap(r, c);
        }
        for (int j = 0; j < m; j++) {
            if (a[r][j] == w[r] && a[r][j] == h[j] && a[r][j] < k) {
                cnt[j]--;
            }
        }
        w[r] = max(w[r], k);
        if (k > h[c]) {
            h[c] = k;
            if (w[r] == k) {
                cnt[c] = 1;
            } else {
                cnt[c] = 0;
            }
        } else if (k == h[c] && k != a[r][c]) {
            if (k == w[r]) {
                cnt[c]++;
            }
        }
        a[r][c] = k;
        /*for (auto &x : cnt)
            cout << x << " ";
        cout << endl;
        for (auto &x : h)
            cout << x << " ";
        cout << endl;
        for (auto &x : w)
            cout << x << " ";
        cout << endl;
        for (auto &x : a) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }*/
        int ans = 0;
        for (auto &x : cnt)
            ans += x;
        cout << ans << endl;
    }
    return 0;
}