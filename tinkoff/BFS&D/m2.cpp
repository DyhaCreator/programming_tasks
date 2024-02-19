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
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[0][0] = 0;
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<ll, ll> index = q.front();
        q.pop();

        int y = index.first;
        int x = index.second;

        while (y < n && map[y][x] == 0) {
            y++;
        }
        if (y == n || map[y][x] == 1) y--;
        if (dist[y][x] == INF) {
            q.push({y, x});
            dist[y][x] = dist[index.first][index.second] + 1;
        }

        y = index.first;
        x = index.second;
        while (x < m && map[y][x] == 0) {
            x++;
        }
        if (x == m || map[y][x] == 1) x--;
        if (dist[y][x] == INF) {
            q.push({y, x});
            dist[y][x] = dist[index.first][index.second] + 1;
        }

        y = index.first;
        x = index.second;
        while (y >= 0 && map[y][x] == 0) {
            y--;
        }
        if (y == -1 || map[y][x] == 1) y++;
        if (dist[y][x] == INF) {
            q.push({y, x});
            dist[y][x] = dist[index.first][index.second] + 1;
        }

        y = index.first;
        x = index.second;
        while (x >= 0 && map[y][x] == 0) {
            x--;
        }
        if (x == -1 || map[y][x] == 1) x++;
        if (dist[y][x] == INF) {
            q.push({y, x});
            dist[y][x] = dist[index.first][index.second] + 1;
        }
    }
    /*for (auto &x : dist) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/
    int min2 = INF;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 2) {
                min2 = std::min(min2, dist[y][x]);
            }
        }
    }
    cout << min2 << endl;
    return 0;
}