#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

int n;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

vector<vector<int>> bfs(int2 start) {
    vector<vector<int>> visited(n, vector<int>(n, INF));
    visited[start.y][start.x] = 0;
    queue<int2> q;
    q.push(start);

    while (!q.empty()) {
        int2 index = q.front();
        q.pop();

        int x = index.x;
        int y = index.y;

        if ((x > 1 && y > 0) && visited[y - 1][x - 2] == INF) {
            q.push(int2(x - 2, y - 1));
            visited[y - 1][x - 2] = visited[y][x] + 1;
        }
        if ((x > 0 && y > 1) && visited[y - 2][x - 1] == INF) {
            q.push(int2(x - 1, y - 2));
            visited[y - 2][x - 1] = visited[y][x] + 1;
        }
        if ((x < n - 1 && y > 1) && visited[y - 2][x + 1] == INF) {
            q.push(int2(x + 1, y - 2));
            visited[y - 2][x + 1] = visited[y][x] + 1;
        }
        if ((x < n - 2 && y > 0) && visited[y - 1][x + 2] == INF) {
            q.push(int2(x + 2, y - 1));
            visited[y - 1][x + 2] = visited[y][x] + 1;
        }
        if ((x > 0 && y < n - 1) && visited[y + 1][x - 2] == INF) {
            q.push(int2(x - 2, y + 1));
            visited[y + 1][x - 2] = visited[y][x] + 1;
        }
        if ((x > 1 && y < n - 2) && visited[y + 2][x - 1] == INF) {
            q.push(int2(x - 1, y + 2));
            visited[y + 2][x - 1] = visited[y][x] + 1;
        }
        if ((x < n - 2 && y < n - 1) && visited[y + 1][x + 2] == INF) {
            q.push(int2(x + 2, y + 1));
            visited[y + 1][x + 2] = visited[y][x] + 1;
        }
        if ((x < n - 1 && y < n - 2) && visited[y + 2][x + 1] == INF) {
            q.push(int2(x + 1, y + 2));
            visited[y + 2][x + 1] = visited[y][x] + 1;
        }
    }
    return visited;
}

int main() {
    cin >> n;
    int2 first;
    cin >> first.x >> first.y;
    int2 second;
    cin >> second.x >> second.y;

    first.x--;
    first.y--;
    second.x--;
    second.y--;

    vector<vector<int>> dist1 = bfs(first);
    vector<vector<int>> dist2 = bfs(second);

    /*for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << dist1[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << dist2[y][x] << " ";
        }
        cout << endl;
    }*/

    int minx = INF;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (dist1[y][x] % 2 == dist2[y][x] % 2 && minx > std::max(dist1[y][x], dist2[y][x])) {
                minx = std::max(dist1[y][x], dist2[y][x]);
            }
        }
    }
    if (minx == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << minx << endl;
    return 0;
}