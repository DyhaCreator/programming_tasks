#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    a[1][1] = 1;
    for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= m; x++) {
            if (y == 1 && x == 1) {

            } else {
                if (y >= 2 && x >= 1) {
                    a[y][x] += a[y - 2][x - 1];
                }
                if (y >= 1 && x >= 2) {
                    a[y][x] += a[y - 1][x - 2];
                }
                if (y < n && x >= 2) {
                    a[y][x] += a[y + 1][x - 2];
                }
                if (y >= 2 && x < m) {
                    a[y][x] += a[y - 2][x + 1];
                }
            }
            cout << a[y][x] << " ";
        }
        cout << endl;
    }
    return 0;
}