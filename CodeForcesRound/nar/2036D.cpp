#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s)
        cin >> x;
    vector<vector<int>> a(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            a[y][x] = s[y][x] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < min(n, m) / 2; i++) {
        vector<int> o = {};
        for (int j = 0; j < m - i * 2; j++)
            o.push_back(a[i][j + i]);
        for (int j = 1; j < n - i * 2; j++)
            o.push_back(a[j + i][m - i - 1]);
        for (int j = 1; j < m - i * 2; j++)
            o.push_back(a[n - i - 1][m - j - i - 1]);
        for (int j = 1; j < n - i * 2 - 1; j++)
            o.push_back(a[n - j - i - 1][i]);

        for (int i = 0; i < o.size(); i++) {
            if (o[i] == 1 && o[(i + 1) % o.size()] == 5 && o[(i + 2) % o.size()] == 4 && o[(i + 3) % o.size()] == 3) {
                ans++;
            }
        }
        /*for (auto &x : o)
            cout << x << " ";
        cout << endl;*/
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}