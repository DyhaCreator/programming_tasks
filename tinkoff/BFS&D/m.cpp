#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    for (auto &x : map) {
        for (auto &y : x) {
            cin >> y;
        }
    }

    vector<vector<int>> used(n, vector<int>(m, INF));
    used[0][0] = 0;
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<ll, ll> index = q.front();
        q.pop();

        int x = index.second;
        int y = index.first;

        /*if (x > 0 && (map[y][x - 1] == 0 || map[y][x - 1] == 2) && used[y][x - 1] == INF) {
            q.push({y, x - 1});
            used[y][x - 1] = used[y][x] + 1;
        }
        if (y > 0 && (map[y - 1][x] == 0 || map[y - 1][x] == 2) && used[y - 1][x] == INF) {
            q.push({y - 1, x});
            used[y - 1][x] = used[y][x] + 1;
        }
        if (x < m - 1 && (map[y][x + 1] == 0 || map[y][x + 1] == 2) && used[y][x + 1] == INF) {
            q.push({y, x + 1});
            used[y][x + 1] = used[y][x] + 1;
        }
        if (y < n - 1 && (map[y + 1][x] == 0 || map[y + 1][x] == 2) && used[y + 1][x] == INF) {
            q.push({y + 1, x});
            used[y + 1][x] = used[y][x] + 1;
        }*/

        int x2 = x;
        int y2 = y;
        while (x2 < m && map[y2][x2] != 1) {
            x2++;
        }
        x2--;
        if (used[y2][x2] == INF) {
            q.push({y2, x2});
            used[y2][x2] = used[y][x] + 1;
        }
        x2 = x;
        y2 = y;
        while (y2 < n && map[y2][x2] != 1) {
            y2++;
            // cout << y2 < n << endl;
        }
        y2--;
        if (used[y2][x2] == INF) {
            q.push({y2, x2});
            used[y2][x2] = used[y][x] + 1;
        }
        x2 = x;
        y2 = y;
        while (y2 >= 0 && map[y2][x2] != 1) {
            y2--;
            // cout << y2 < n << endl;
        }
        y2++;
        if (used[y2][x2] == INF) {
            q.push({y2, x2});
            used[y2][x2] = used[y][x] + 1;
        }
        x2 = x;
        y2 = y;
        while (x2 >= 0 && map[y2][x2] != 1) {
            x2--;
            // cout << y2 < n << endl;
        }
        x2++;
        if (used[y2][x2] == INF) {
            q.push({y2, x2});
            used[y2][x2] = used[y][x] + 1;
        }
    }
    for (auto &x : used) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    int min2 = INF;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 2) {
                min2 = std::min(used[y][x], min2);
            }
        }
    }
    if (min2 == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << min2 << endl;
    return 0;
}