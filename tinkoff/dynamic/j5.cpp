#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> map = vector<vector<int >> (n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<int >> a = vector<vector<int >> (n + 1, vector<int>(m + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            a[y][x] = a[y - 1][x] + map[y - 1][x - 1];
            if (map[y - 1][x - 1] == 0) {
                a[y][x] = 0;
            }
        }
    }
    vector<vector<int >> b = vector<vector<int >> (n + 1, vector<int>(m + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            b[y][x] = b[y][x - 1] + map[y - 1][x - 1];
            if (map[y - 1][x - 1] == 0) {
                b[y][x] = 0;
            }
        }
    }
    vector<vector<int >> c = vector<vector<int >> (n + 1, vector<int>(m + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (min(a[y][x], b[y][x]) <= c[y - 1][x - 1] + 1) {
                c[y][x] = min(a[y][x], b[y][x]);
            } else {
                if (c[y - 1][x - 1] + 1 <= a[y][x] && c[y - 1][x - 1] + 1 <= b[y][x]) {
                    c[y][x] = c[y - 1][x - 1] + 1;
                } else {
                    c[y][x] = map[y - 1][x - 1];
                }
            }
        }
    }
    int maxS = 0;
    int lx = 0;
    int ly = 0;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (c[y][x] >= maxS) {
                maxS = c[y][x];
                lx = x - c[y][x];
                ly = y - c[y][x];
            }
        }
    }
    cout << maxS << "\n" << ly + 1 << " " << lx + 1 << "\n";
    return 0;
}
/*

3 5
1 1 0 0 0
1 1 1 1 1
0 0 0 1 1

10 11
0 0 1 1 0 0 1 1 0 1 0
0 0 1 1 0 0 1 1 0 1 1
0 0 1 1 1 1 1 1 0 1 0
0 0 0 1 1 1 1 1 0 1 1
0 0 1 1 1 1 1 1 0 1 0
0 0 0 1 1 1 1 1 0 1 1
0 0 1 1 1 1 1 1 0 1 0
0 0 1 1 0 0 1 1 0 1 0
0 0 1 1 0 0 1 1 0 1 1
0 0 1 1 0 0 1 1 0 1 1 

0 0 1 1 0 0 1 1 0 1 0 
0 0 1 2 0 0 1 2 0 1 1 
0 0 1 2 1 1 1 2 0 1 0 
0 0 0 1 2 2 2 2 0 1 1 
0 0 1 1 2 3 3 3 0 1 0 
0 0 0 1 2 3 4 4 0 1 1 
0 0 1 1 2 3 4 5 0 1 0 
0 0 1 2 0 0 1 2 0 1 0 
0 0 1 2 0 0 1 2 0 1 1 
0 0 1 2 0 0 1 2 0 1 2 

*/