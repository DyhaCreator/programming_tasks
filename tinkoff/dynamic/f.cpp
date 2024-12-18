#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int xp, yp;
    cin >> xp >> yp;
    vector<vector<int >> a = vector<vector<int >> (8, vector<int>(8));
    a[yp - 1][xp - 1] = 1;
    for (int y = 1; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (x == xp - 1 && y == yp - 1) {} else if (x == 0) {
                a[y][x] = a[y - 1][x + 1];
            } else if (x == 7) {
                a[y][x] = a[y - 1][x - 1];
            } else {
                a[y][x] = a[y - 1][x + 1] + a[y - 1][x - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        ans += a[7][i];
    }
    cout << ans << endl;
    return 0;
}