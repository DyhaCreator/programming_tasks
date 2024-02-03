#include <iostream>
#include <vector>
#include <deque>
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

vector<vector<int2>> g;
int n, m, s;

vector<int> bfs01(int start) {
    int step = 0;
    vector<int> visited(n, INF);
    deque<int2> d;

    d.push_back(int2(start, 0));
    visited[start] = step;
    /*for (auto &x : visited)
        cout << x << " ";
    cout << endl;*/
    // int lastIndex = start;
    while (!d.empty()) {
        int2 index = d.front();
        d.pop_front();
        // visited[index.x] = visited[lastIndex] + index.y;
        /*for (auto &x : visited)
            cout << x << " ";
        cout << endl;*/
        for (auto &x : g[index.x]) {
            if (visited[x.x] > visited[index.x] + x.y) {
                visited[x.x] = visited[index.x] + x.y;
                if (x.y == 1) {
                    d.push_back(x);
                } else {
                    d.push_front(x);
                }
            }
        }
        // lastIndex = index.x;
    }

    return visited;
}

int main() {
    cin >> n >> m >> s;
    g = vector<vector<int2>>(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back(int2(b - 1, c));
        g[b - 1].push_back(int2(a - 1, c));
    }
    /*for (int i = 0; i < n; i++) {
        cout << i << endl;
        for (auto &x : g[i]) {
            cout << x.x << " " << x.y << endl;
        }
    }*/

    vector<int> visited = bfs01(s - 1);

    for (auto &x : visited)
        if (x == INF) {
            cout << -1 << " ";
        } else {
            cout << x << " ";
        }
    cout << endl;
    return 0;
}