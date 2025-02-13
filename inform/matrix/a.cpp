#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> a[x][y];
        }
    }
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < m; x++) {
            if (y != x && a[y] == a[x]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}