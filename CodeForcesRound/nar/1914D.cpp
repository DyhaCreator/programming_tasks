#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    vector<vector<int>> dp0(3, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
        dp0[0][i + 1] = max(dp0[0][i], a[i]);
    for (int i = 0; i < n; i++)
        dp0[1][i + 1] = max(dp0[1][i], b[i]);
    for (int i = 0; i < n; i++)
        dp0[2][i + 1] = max(dp0[2][i], c[i]);
    vector<vector<pair<int, int>>> dp1(3, vector<pair<int, int>>(n + 1));

    for (int i = 1; i < n; i++) {
        dp1[0][i + 1].F = max(dp1[0][i].F, a[i] + dp0[1][i]);
        dp1[0][i + 1].S = max(dp1[0][i].S, a[i] + dp0[2][i]);
    }
    for (int i = 1; i < n; i++) {
        dp1[1][i + 1].F = max(dp1[1][i].F, b[i] + dp0[0][i]);
        dp1[1][i + 1].S = max(dp1[1][i].S, b[i] + dp0[2][i]);
    }
    for (int i = 1; i < n; i++) {
        dp1[2][i + 1].F = max(dp1[2][i].F, c[i] + dp0[0][i]);
        dp1[2][i + 1].S = max(dp1[2][i].S, c[i] + dp0[1][i]);
    }

    /*
    for (auto &x : dp0) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : dp1) {
        for (auto &y : x)
            cout << y.F << " " << y.S << "  ";
        cout << endl;
    }*/

    int ans = 0;
    for (int i = 2; i < n; i++) {
        ans = max(ans, a[i] + dp1[1][i].S);
        ans = max(ans, a[i] + dp1[2][i].S);
        ans = max(ans, b[i] + dp1[0][i].S);
        ans = max(ans, b[i] + dp1[2][i].F);
        ans = max(ans, c[i] + dp1[0][i].F);
        ans = max(ans, c[i] + dp1[1][i].F);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}