#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n, m;

void dfs(int y, int x, int py, int px, vector<vector<int>> &a, vector<vector<int>> &used, int &f) {
    used[y][x] = 2;
    if (y > 0 && used[y - 1][x] == 2 && y - 1 != py)
        f = 1;
    if (y < n - 1 && used[y + 1][x] == 2 && y + 1 != py)
        f = 1;
    if (x > 0 && used[y][x - 1] == 2 && x - 1 != px)
        f = 1;
    if (x < m + 1 && used[y][x + 1] == 2 && x + 1 != px)
        f = 1;

    if (y > 0 && used[y - 1][x] == 0 && a[y - 1][x] == a[y][x])
        dfs(y - 1, x, y, x, a, used, f);
    if (y < n - 1 && used[y + 1][x] == 0 && a[y + 1][x] == a[y][x])
        dfs(y + 1, x, y, x, a, used, f);
    if (x > 0 && used[y][x - 1] == 0 && a[y][x - 1] == a[y][x])
        dfs(y, x - 1, y, x, a, used, f);
    if (x < m + 1 && used[y][x + 1] == 0 && a[y][x + 1] == a[y][x])
        dfs(y, x + 1, y, x, a, used, f);
    used[y][x] = 1;
}

void dfs2(int y, int x, vector<vector<int>> &a, 
    vector<vector<int>> &used, 
    vector<vector<int>> &mx, int len, int &ans) {
    used[y][x] = len;
    mx[y][x] = max(mx[y][x], used[y][x]);
    vector<int> mm = {};
    if (y > 0 && used[y - 1][x] == 0 && a[y - 1][x] == a[y][x]) {
        dfs2(y - 1, x, a, used, mx, len + 1, ans);
        mx[y][x] = max(mx[y][x], mx[y - 1][x]);
        mm.push_back(mx[y - 1][x]);
    }
    if (y < n - 1 && used[y + 1][x] == 0 && a[y + 1][x] == a[y][x]) {
        dfs2(y + 1, x, a, used, mx, len + 1, ans);
        mx[y][x] = max(mx[y][x], mx[y + 1][x]);
        mm.push_back(mx[y + 1][x]);
    }
    if (x > 0 && used[y][x - 1] == 0 && a[y][x - 1] == a[y][x]) {
        dfs2(y, x - 1, a, used, mx, len + 1, ans);
        mx[y][x] = max(mx[y][x], mx[y][x - 1]);
        mm.push_back(mx[y][x - 1]);
    }
    if (x < m + 1 && used[y][x + 1] == 0 && a[y][x + 1] == a[y][x]) {
        dfs2(y, x + 1, a, used, mx, len + 1, ans);
        mx[y][x] = max(mx[y][x], mx[y][x + 1]);
        mm.push_back(mx[y][x + 1]);
    }
    if (mm.size() > 1) {
        int mx_index = 0;
        for (int i = 0; i < mm.size(); i++) {
            if (mm[i] > mm[mx_index]) {
                mx_index = i;
            }
        }
        int sec_mx_index = (mx_index + 1) % mm.size();
        for (int i = 0; i < mm.size(); i++) {
            if (mm[i] > mm[sec_mx_index] && i != mx_index) sec_mx_index = i;
        }
        ans = max(ans, mm[mx_index] + mm[sec_mx_index] - 2 * used[y][x] + 1);
    } else {
        ans = max(ans, mx[y][x]);
    }
}

int sm(int y, int x, vector<vector<int>> &a) {
    int ans = 0;
    if (y > 0 && a[y - 1][x] == a[y][x])
        ans++;
    if (y < n - 1 && a[y + 1][x] == a[y][x])
        ans++;
    if (x > 0 && a[y][x - 1] == a[y][x])
        ans++;
    if (x < m - 1 && a[y][x + 1] == a[y][x])
        ans++;
    return ans;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    map<int, int> mp;
    for (auto &x : a) {
        for (auto &y : x)
            mp[y]++;
    }
    vector<vector<int>> used(n, vector<int>(m));
    int ans = 1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (used[y][x] == 0) {
                int f = 0;
                dfs(y, x, y, x, a, used, f);
                if (f) {
                    ans = max(ans, mp[a[y][x]]);
                }
            }
        }
    }
    used = vector<vector<int>> (n, vector<int>(m));
    vector<vector<int>> mx(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (used[y][x] == 0) {
                dfs2(y, x, a, used, mx, 1, ans);
            }
        }
    }
    /*for (auto &x : used) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
    for (auto &x : mx) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << ans << endl;
    return 0;
}