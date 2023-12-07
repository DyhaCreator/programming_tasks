#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> a = vector<vector<int >> (n + 1, vector<int>(m + 1));
    a[1][1] = 2;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            for (int i = 1; i < min(x, y); i++) {
                if (a[y - i][x] == 2 || a[y - i][x - i] == 2 || a[y][x - i] == 2) {
                    a[y][x] = 1;
                    break;
                }
            }
            if (a[y][x] != 1) {
                if (y < x) {
                    for (int i = y; i < x; i++) {
                        if (a[y][x - i] == 2) {
                            a[y][x] = 1;
                            break;
                        }
                    }
                } else {
                    for (int i = x; i < y; i++) {
                        if (a[y - i][x] == 2) {
                            a[y][x] = 1;
                            break;
                        }
                    }
                }
            }
            if (a[y][x] != 1) {
                a[y][x] = 2;
            }
        }
    }
    cout << a[n][m] << endl;
    return 0;
}