#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> used(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    q.push({0, 0});
    used[0][0] = 0;
    while (!q.empty()) {
        int y = q.front().F;
        int x = q.front().S;
        q.pop();
        if (y > 0 && a[y - 1][x] != '#' && used[y - 1][x] > used[y][x] + 1) {
            q.push({y - 1, x});
            used[y - 1][x] = used[y][x] + 1;
        }
        if (x > 0 && a[y][x - 1] != '#' && used[y][x - 1] > used[y][x] + 1) {
            q.push({y, x - 1});
            used[y][x - 1] = used[y][x] + 1;
        }
        if (y < n - 1 && a[y + 1][x] != '#' && used[y + 1][x] > used[y][x] + 1) {
            q.push({y + 1, x});
            used[y + 1][x] = used[y][x] + 1;
        }
        if (x < m - 1 && a[y][x + 1] != '#' && used[y][x + 1] > used[y][x] + 1) {
            q.push({y, x + 1});
            used[y][x + 1] = used[y][x] + 1;
        }
    }
    if (used[n - 1][m - 1] >= INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << used[n - 1][m - 1] << endl;
    return 0;
}