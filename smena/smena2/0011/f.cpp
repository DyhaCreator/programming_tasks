#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    if (n * m == 1) {
        cout << 0 << endl;
        return 0;
    }
    int mx1 = 0;
    int mx2 = 0;
    vector<vector<int>> a(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            a[y][x] = (n + x + 1) * (y + 1);
            mx1 = a[y][x];
        }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            b[y][x] = (m + y + 1) * (x + 1);
            mx2 = b[y][x];
        }
    }
    if (mx1 < mx2) {
        for (auto &x : a) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
    } else {
        for (auto &x : b) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
    }
    return 0;
}