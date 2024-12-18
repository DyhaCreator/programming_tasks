#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

void dfs(int start, vector<int> &visited, int step) {
    visited[start] = step;
    for (auto &x : g[start]) {
        if (visited[x] == 0) {
            dfs(x, visited, step + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g = vector<vector<int>>(n, vector<int>());
    vector<int2>qw(m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        qw.push_back(int2(a, b));
    }

    vector<int> visited(n);

    dfs(0, visited, 1);

    for (auto &x : qw) {
        if (abs(visited[x.x - 1] - visited[x.y - 1]) == 1) {
            cout << x.x << " " << x.y << endl;
        }
    }
    return 0;
}