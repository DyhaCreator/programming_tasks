#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    
    vector<vector<ll>> dp1(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp2(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp3(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp4(n + 1, vector<ll>(m + 1));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            dp1[y + 1][x + 1] = max(dp1[y + 1][x], dp1[y][x + 1]) + a[y][x];    
        }
    }
    for (int y = n - 1; y >= 0; y--) {
        for (int x = m - 1; x >= 0; x--) {
            dp2[y][x] = max(dp2[y + 1][x], dp2[y][x + 1]) + a[y][x];
        }
    }
    for (int y = n - 1; y >= 0; y--) {
        for (int x = 0; x < m; x++) {
            dp3[y][x + 1] = max(dp3[y][x], dp3[y + 1][x + 1]) + a[y][x];
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = m - 1; x >= 0; x--) {
            dp4[y + 1][x] = max(dp4[y][x], dp4[y + 1][x + 1]) + a[y][x];
        }
    }

    for (auto &x : dp1) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : dp2) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : dp3) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : dp4) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }


    ll ans = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << y << " " << x << endl;
            if (y + 1 < n && x + 1 < m) cout << dp1[y][x + 1] + dp3[y][x] + dp2[y + 1][x] + dp4[y + 1][x + 1] << " ";
            if (y - 1 >= 0 && y + 1 < n && x + 1 < m) cout << dp1[y][x + 1] + dp3[y - 1][x + 1] + dp2[y + 1][x] + dp4[y][x] << " ";
            if (y - 1 >= 0 && y + 1 < n && x + 1 < m) cout << dp1[y][x + 1] + dp3[y - 1][x + 1] + dp2[y + 1][x] + dp4[y + 1][x + 1] << " ";
            if (y - 1 >= 0 && x + 1 < m) cout << dp1[y][x + 1] + dp3[y - 1][x + 1] + dp2[y][x + 1] + dp4[y][x] << " ";
            if (y + 1 < n && x + 1 < m) cout << dp1[y + 1][x] + dp3[y + 1][x + 1] + dp2[y][x + 1] + dp4[y][x] << " ";
            cout << endl;
        }
    }
    cout << ans << endl;
    return 0;
}