#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            string s;
            cin >> s;
            if (s == "x") {
                a[y][x] = INF;
            } else {
                a[y][x] = stoi(s);
            }
        }
    }

    int y = n - 1;
    int x = k - 1;
    int d = 0;
    int sum = 0;
    int f = 0;
    while (y >= 0 && y < n && x >= 0 && x < m) {
        if (a[y][x] != -INF) sum += a[y][x];
        // cout << y << " " << x << endl;
        a[y][x] = -INF;
        if (d == 0 && y - 1 < 0) f = 1;
        else if (d == 1 && x + 1 == m) f = 1;
        else if (d == 2 && y + 1 == n) f = 1;
        else if (d == 3 && x - 1 < 0) f = 1;
        if (f == 1) break;
        if (d == 0 && a[y - 1][x] == INF) d++;
        else if (d == 1 && a[y][x + 1] == INF) d++;
        else if (d == 2 && a[y + 1][x] == INF) d++;
        else if (d == 3 && a[y][x - 1] == INF) d++;

        if (d == 0 && a[y - 1][x] == -INF) {
            y--;
            break;
        } else if (d == 1 && a[y][x + 1] == -INF) {
            x++;
            break;
        } else if (d == 2 && a[y + 1][x] == -INF) {
            y++;
            break;
        } else if (d == 3 && a[y][x - 1] == -INF) {
            x--;
            break;
        }

        if (d == 0) y--;
        else if (d == 1) x++;
        else if (d == 2) y++;
        else if (d == 3) x--;
    }
    if (f == 1) {
        cout << 0 << endl;
        cout << sum << endl;
    } else {
        cout << y + 1 << " " << x + 1 << endl;
        cout << sum << endl;
    }
    return 0;
}