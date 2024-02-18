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
    int n;
    cin >> n;
    int2 start = int2();
    cin >> start.x >> start.y;
    int2 finish = int2();
    cin >> finish.x >> finish.y;

    start.x--;
    start.y--;

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
    if (visited[finish.y - 1][finish.x - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << visited[finish.y - 1][finish.x - 1] << endl;
    /*for (auto &x : visited) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/
    return 0;
}