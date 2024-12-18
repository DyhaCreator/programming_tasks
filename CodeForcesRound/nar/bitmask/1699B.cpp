#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 4 == 0 && j % 4 == 0) {
                a[i][j] = 1;
                if (i < n - 3) a[i + 3][j] = 1;
                if (i < n - 1 && j < m - 1) a[i + 1][j + 1] = 1;
                if (i < n - 2 && j < m - 1) a[i + 2][j + 1] = 1;
                if (i < n - 1 && j < m - 2) a[i + 1][j + 2] = 1;
                if (i < n - 2 && j < m - 2) a[i + 2][j + 2] = 1;
                if (j < m - 3) a[i][j + 3] = 1;
                if (i < n - 3 && j < m - 3) a[i + 3][j + 3] = 1;
            }
        }
    }
    for (auto &x : a) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}