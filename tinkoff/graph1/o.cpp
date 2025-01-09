#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    r--;c--;
    int ml, mr;
    cin >> ml >> mr;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<pair<int, int>>> used(n, vector<pair<int, int>>(m, {INF, INF}));
    pair<int, int> pINF = {INF, INF};
    deque<pair<int, int>> q;
    used[r][c] = {0, 0};
    q.push_back({r, c});
    while (!q.empty()) {
        int y = q.front().F;
        int x = q.front().S;
        q.pop_front();
        if (y > 0 && a[y - 1][x] != '*' && used[y - 1][x] == pINF) {
            used[y - 1][x] = used[y][x];
            q.push_front({y - 1, x});
        }
        if (y < n - 1 && a[y + 1][x] != '*' && used[y + 1][x] == pINF) {
            used[y + 1][x] = used[y][x];
            q.push_front({y + 1, x});used[y][x].F;
        }
        if (x > 0 && a[y][x - 1] != '*' && used[y][x - 1] == pINF) {
            used[y][x - 1] = {used[y][x].F + 1, used[y][x].S};
            q.push_back({y, x - 1});
        }
        if (x < m - 1 && a[y][x + 1] != '*' && used[y][x + 1] == pINF) {
            used[y][x + 1] = {used[y][x].F, used[y][x].S + 1};
            q.push_back({y, x + 1});
        }
    }
    int ans = 0;
    for (auto &x : used) {
        for (auto &y : x) {
            if (y.F <= ml && y.S <= mr) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}