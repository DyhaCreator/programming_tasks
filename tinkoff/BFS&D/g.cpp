#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for (auto &x : map)
        cin >> x;

    vector<vector<int>> visited(n, vector<int>(m, INF));
    visited[0][0] = 0;
    queue<int2> q;
    q.push(int2(0, 0));
    while (!q.empty()) {
        int2 index = q.front();
        q.pop();
        int y = index.x;
        int x = index.y;

        // cout << y << " " << x << endl;

        if (x > 0 && map[y][x - 1] == '.' && visited[y][x - 1] == INF) {
            q.push(int2(y, x - 1));
            visited[y][x - 1] = visited[y][x] + 1;
        }
        if (y > 0 && map[y - 1][x] == '.' && visited[y - 1][x] == INF) {
            q.push(int2(y - 1, x));
            visited[y - 1][x] = visited[y][x] + 1;
        }
        if (x < m - 1 && map[y][x + 1] == '.' && visited[y][x + 1] == INF) {
            q.push(int2(y, x + 1));
            visited[y][x + 1] = visited[y][x] + 1;
        }
        if (y < n - 1 && map[y + 1][x] == '.' && visited[y + 1][x] == INF) {
            q.push(int2(y + 1, x));
            visited[y + 1][x] = visited[y][x] + 1;
        }
    }

    /*for (auto &x : visited) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/

    if (visited[n - 1][m - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << visited[n - 1][m - 1] << endl;

    return 0;
}