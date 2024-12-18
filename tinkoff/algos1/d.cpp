#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < q; i++) {
        ll lx, ly, rx, ry, d;
        cin >> lx >> ly >> rx >> ry >> d;
        a[lx - 1][ly - 1] += d;
        a[lx - 1][ry] -= d;
        a[rx][ly - 1] -= d;
        a[rx][ry] += d;
    }
    vector<vector<ll>> b(n, vector<ll>(m, 0));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            b[y][x] += a[y][x];
            if (y > 0 && x > 0) {
                b[y][x] -= b[y - 1][x - 1];
            }
            if (y > 0) {
                b[y][x] += b[y - 1][x];
            }
            if (x > 0) {
                b[y][x] += b[y][x - 1];
            }
            /*if (y > 0) {
                b[y][x] += b[y - 1][x];
            }
            if (x > 0) {
                b[y][x] += b[y][x - 1];
            }*/
        }
    }
    /*for (auto &x : a) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;*/
    for (auto &x : b) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}