#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

int n, m;

int dfs(vector<vector<int>>&map, vector<vector<pair<int, int>>>&matrix, int y, int x, int sum, vector<int>&visited) {
    visited[y * m + x] = 1;

    for (auto &[a, b] : matrix[y * m + x]) {
        if (visited[a * m + b] == 0 && map[a][b] != 0) {
            int ans = dfs(map, matrix, a, b, 0, visited);
            //cout << a << " " << b << " " << ans << endl;
            sum += ans;
        } 
    }

    return sum + map[y][x];
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        vector<vector<int>>map(n, vector<int>(m));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> map[y][x];
            }
        }
        vector<vector<pair<int, int>>>matrix(n * m, vector<pair<int, int>>());
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                //cout << y << " " << x << endl;
                //if (map[y][x] > 0) {
                    if (y > 0) {
                        if (map[y - 1][x] > 0) {
                            matrix[y * m + x].push_back(make_pair(y - 1, x));
                        }
                    }
                    if (x > 0) {
                        if (map[y][x - 1] > 0) {
                            matrix[y * m + x].push_back(make_pair(y, x - 1));
                        }
                    }
                    if (y < n - 1) {
                        if (map[y + 1][x] > 0) {
                            matrix[y * m + x].push_back(make_pair(y + 1, x));
                        }
                    }
                    if (x < m - 1) {
                        if (map[y][x + 1] > 0) {
                            matrix[y * m + x].push_back(make_pair(y, x + 1));
                        }
                    }
                //}
            }
        }
        vector<int>visited(n * m, 0);
        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (visited[y * m + x] == 0 && map[y][x] > 0) {
                    ans = std::max(dfs(map, matrix, y, x, 0, visited), ans);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
3 3
1 2 0
3 4 0
0 0 5
1 1
0
3 3
0 1 1
1 0 1
1 1 1
5 5
1 1 1 1 1
1 0 0 0 1
1 0 5 0 1
1 0 0 0 1
1 1 1 1 1
5 5
1 1 1 1 1
1 0 0 0 1
1 1 4 0 1
1 0 0 0 1
1 1 1 1 1

8 1
1
2
1
2
0
0
1
1

*/