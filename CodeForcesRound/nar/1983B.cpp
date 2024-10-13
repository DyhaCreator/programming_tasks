#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x) {
            char ch;
            cin >> ch;
            y = ch - '0';
        }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (auto &x : b) {
        for (auto &y : x) {
            char ch;
            cin >> ch;
            y = ch - '0';
        }
    }
    for (int y = 0; y < n - 1; y++) {
        for (int x = 0; x < m - 1; x++) {
            if (a[y][x] == b[y][x]) continue;
            if (a[y][x] == 0) {
                if (b[y][x] == 1) {
                    a[y][x] = (a[y][x] + 1) % 3;
                    a[y][m - 1] = (a[y][m - 1] + 2) % 3;
                    a[n - 1][x] = (a[n - 1][x] + 2) % 3;
                    a[n - 1][m - 1] = (a[n - 1][m - 1] + 1) % 3;
                } else {
                    a[y][x] = (a[y][x] + 2) % 3;
                    a[y][m - 1] = (a[y][m - 1] + 1) % 3;
                    a[n - 1][x] = (a[n - 1][x] + 1) % 3;
                    a[n - 1][m - 1] = (a[n - 1][m - 1] + 2) % 3;
                }
            } else if (a[y][x] == 1) {
                if (b[y][x] == 0) {
                    a[y][x] = (a[y][x] + 2) % 3;
                    a[y][m - 1] = (a[y][m - 1] + 1) % 3;
                    a[n - 1][x] = (a[n - 1][x] + 1) % 3;
                    a[n - 1][m - 1] = (a[n - 1][m - 1] + 2) % 3;
                } else {
                    a[y][x] = (a[y][x] + 1) % 3;
                    a[y][m - 1] = (a[y][m - 1] + 2) % 3;
                    a[n - 1][x] = (a[n - 1][x] + 2) % 3;
                    a[n - 1][m - 1] = (a[n - 1][m - 1] + 1) % 3;
                }
            } else {
                if (b[y][x] == 0) {
                    a[y][x] = (a[y][x] + 1) % 3;
                    a[y][m - 1] = (a[y][m - 1] + 2) % 3;
                    a[n - 1][x] = (a[n - 1][x] + 2) % 3;
                    a[n - 1][m - 1] = (a[n - 1][m - 1] + 1) % 3;
                } else {
                    a[y][x] = (a[y][x] + 2) % 3;
                    a[y][m - 1] = (a[y][m - 1] + 1) % 3;
                    a[n - 1][x] = (a[n - 1][x] + 1) % 3;
                    a[n - 1][m - 1] = (a[n - 1][m - 1] + 2) % 3;
                }
            }
            /*for (auto &x : a) {
                for (auto &y : x)
                    cout << y << " ";
                cout << endl;
            }
            cout << "----" << endl;*/
        }
    }
    if (a == b)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}