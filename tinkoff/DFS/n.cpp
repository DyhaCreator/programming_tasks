#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m;
vector<vector<int>> g;

void dfs(int start, vector<int> &visited, int sum) {
    cout << start << endl;
    visited[start] = sum;
    /*for (auto &x : visited)
        cout << x << " ";
    cout << endl;*/
    for (int i = 0; i < n; i++) {
        if (g[start][i] != 0 && (visited[i] == -1 || visited[i] >= max(sum, g[start][i]))) {
            dfs(i, visited, max(sum, g[start][i]));
        }
    }
}

int main() {
    cin >> n >> m;

    g = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < m; i++) {
        int a, b, z;
        cin >> a >> b >> z;
        g[a - 1][b - 1] = z;
        g[b - 1][a - 1] = z;
    }

    int a, b;
    cin >> a >> b;

    /*for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << g[y][x] << " ";
        }
        cout << endl;
    }*/

    vector<int> visited(n, -1);

    dfs(a - 1, visited, 0);


    cout << visited[b - 1] << endl;
    return 0;
}