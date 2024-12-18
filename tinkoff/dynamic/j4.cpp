#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>map = vector<vector<int>>(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<int>>a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    a[1][1] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (y != 1 || x != 1) {
                if (map[y - 1][x - 1] == 1) {
                    /*if (y > 1 && x > 1) {
                        a[y][x] = a[y - 1][x] * a[y][x - 1] + 1;
                    } else if (x > 1) {
                        a[y][x] = a[y][x - 1] + 1;
                    } else if (y > 1) {
                        a[y][x] = a[y - 1][x] + 1;
                    } else {
                        a[y][x] = 1;
                    }*/
                    a[y][x] = a[y - 1][x] * a[y][x - 1] + 1;
                } else {
                    a[y][x] = 0;
                }
            }
            cout << a[y][x] << " ";
        }
        cout << endl;
    }
    int maxS = 0;
    int lx = 0;
    int ly = 0;
    for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= m; x++) {
            if (a[y][x] > maxS) {
                maxS = a[y][x];
                lx = x - a[y][x];
                ly = y - a[y][x];
            }
        }
    }
    cout << maxS << "\n" << lx + 1 << " " << ly + 1 << "\n";
    return 0;
}
/*

3 5
1 1 0 0 0
1 1 1 1 1
0 0 0 1 1

*/