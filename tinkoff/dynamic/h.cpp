#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    a[1][1] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (x == 1 && y == 1) {

            } else {
                if (y >= 2) {
                    a[y][x] += a[y - 2][x - 1];
                }
                if (x >= 2) {
                    a[y][x] += a[y - 1][x - 2];
                }
                if (y >= 2 && x < m) {
                    a[y][x] += a[y - 2][x + 1];
                }
                if (x >= 2 && y < n) {
                    a[y][x] += a[y + 1][x - 2];
                }
                a[x][y] = a[y][x];
            }
            cout << a[y][x] << " ";
        }
        cout << endl;
    }
    return 0;
}