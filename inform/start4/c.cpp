#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x)
            cin >> y;
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            pref[y + 1][x + 1] = pref[y + 1][x] + pref[y][x + 1] - pref[y][x] + a[y][x];
        }
    }
    int mx = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l <= i; l++) {
                for (int r = 0; r <= j; r++) {
                    // cout << pref[i + 1][j + 1] - pref[i + 1][r] - pref[l][j + 1] + pref[l][r] << endl;
                    mx = max(mx, pref[i + 1][j + 1] - pref[i + 1][r] - pref[l][j + 1] + pref[l][r]);
                }
            }
        }
    }
    /*for (auto &x : pref) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << mx << endl;
    return 0;
}