#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n, m;

int dfs(vector<vector<int>> &a, vector<vector<int>> &used, int y, int x) {
    // cout << y << " " << x << endl;
    used[y][x] = 1;
    int ans = 0;
    if (y + 1 < n && used[y + 1][x] == 0 && a[y + 1][x] != 0)
        ans += dfs(a, used, y + 1, x);
    if (x + 1 < m && used[y][x + 1] == 0 && a[y][x + 1] != 0)
        ans += dfs(a, used, y, x + 1);
    if (y - 1 >= 0 && used[y - 1][x] == 0 && a[y - 1][x] != 0)
        ans += dfs(a, used, y - 1, x);
    if (x - 1 >= 0 && used[y][x - 1] == 0 && a[y][x - 1] != 0)
        ans += dfs(a, used, y, x - 1);
    return ans + a[y][x];
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    vector<vector<int>> used(n, vector<int>(m));
    int ans = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (used[y][x] == 0 && a[y][x] > 0) {
                ans = max(ans, dfs(a, used, y, x));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}