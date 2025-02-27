#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x)
            cin >> y;
    }
    vector<pair<int, int>> ans = {};
    vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));

    for (int y = 0; y < n - 1; y++) {
        for (int x = 0; x < m - 1; x++) {
            if (a[y][x] == 1 && a[y][x + 1] == 1 && a[y + 1][x] == 1 && a[y + 1][x + 1] == 1) {
                b[y][x] = 1;
                b[y + 1][x] = 1;
                b[y][x + 1] = 1;
                b[y + 1][x + 1] = 1;
                ans.push_back({y, x});
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] != b[y][x]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x.F + 1 << " " << x.S + 1 << endl;
    /*for (auto &x : b) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    return 0;
}