#include <iostream>
#include <vector>
#include <deque>
#define ll long long
#define INF -1
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
    deque<int> d;

    d.push_front(start);
    visited[start] = step;
    /*for (auto &x : visited)
        cout << x << " ";
    cout << endl;*/
    while (!d.empty()) {
        int index = d.front();
        d.pop_front();

        for (auto &x : g[index]) {
            if (visited[x.x] == INF) {
                if (x.y == 1) {
                    d.push_back(x.x);
                    visited[x.x] = visited[index] + 1;
                } else {
                    d.push_front(x.x);
                    visited[x.x] = visited[index];
                }
            }
        }
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

    vector<int> visited = bfs01(0);

    for (auto &x : visited)
        cout << x << " ";
    cout << endl;
    return 0;
}