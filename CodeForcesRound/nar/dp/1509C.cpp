#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e2 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp0(n, vector<int>(n, INF));
    vector<vector<int>> dp1(n, vector<int>(n, INF));
    vector<vector<pair<int, int>>> l0(n, vector<pair<int, int>>(n));
    vector<vector<pair<int, int>>> l1(n, vector<pair<int, int>>(n));
    dp0[0] = vector<int>(n, 0);
    dp1[0] = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        l0[i] = {a[i], a[i]};
        l1[i] = {a[i], a[i]};
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0 && dp0[i - 1][j - 1] < INF) {
                dp0[i][j] = dp0[i - 1][j - 1];
            }
            if (j < n - 1 && dp1[i - 1][j + 1] < INF) {
                dp1[i][j] = dp1[i - 1][j + 1];
            }
        }
    }
    for (auto &x : dp0) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : l0) {
        for (auto &y : x)
            cout << y.F << " " << y.S << "  ";
        cout << endl;
    }
    for (auto &x : dp1) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : l1) {
        for (auto &y : x)
            cout << y.F << " " << y.S << "  ";
        cout << endl;
    }
    return 0;
}