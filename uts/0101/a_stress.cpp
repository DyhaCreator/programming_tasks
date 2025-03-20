#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve1(int n, int m, vector<vector<int>> a,
    vector<vector<int>> &qs) {
    int q = qs.size();
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
        //int r, c, k;
        //cin >> r >> c >> k;
        int r = qs[i][0];
        int c = qs[i][1];
        int k = qs[i][2];
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
    }
    return 0;
}


int solve2(int n, int m, int r, int c, int k, vector<vector<int>> a) {
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
    for (int i = 0; i < 1; i++) {
        // int r, c, k;
        // cin >> r >> c >> k;
        r--;c--;
        a[r][c] = k;
        w[r] = max(w[r], a[r][c]);
        h[c] = max(h[c], a[r][c]);
        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (a[y][x] == w[y] && a[y][x] == h[x]) {
                    ans++;
                }
            }
        }
        return ans;
    }
    return 0;
}

int main() {
    int n = 450;
    int m = 450;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x)
            y = rand() % 25;
    }
    for (int i = 0; i < 1; i++) {
        vector<vector<int>> qs = {};
        for (int j = 0; j < 10; j++) {
            int r = rand() % n + 1;
            int c = rand() % m + 1;
            int k = rand() % 25 + a[r - 1][c - 1] + 1;
            qs.push_back({r, c, k});
        }
        ofstream out("test");
        out << n << " " << m << " " << qs.size() << endl;
        for (auto &x : a) {
            for (auto &y : x)
                out << y << " ";
            out << endl;
        }
        for (auto &x : qs)
            out << x[0] << " " << x[1] << " " << x[2] << endl;
        solve1(n, m, a, qs);
        /*if (solve1(n, m, a, qs) != solve2(n, m, a, qs)) {
            for (auto &x : a) {
                for (auto &y : x)
                    cout << y << " ";
                cout << endl;
            }
            cout << solve1(n, m, a, qs) << endl;
            // cout << solve2(n, m, r, c, k, a) << endl;
        }*/
    }
    
    return 0;
}