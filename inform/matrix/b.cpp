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
        for (int x = 0; x < m; x++)
            cin >> a[x][y];
    }
    for (auto &x : a) {
        int fi = -1;
        int si = -1;
        for (int i = 0; i < n; i++) {
            if (x[i] < 0 && fi == -1)
                fi = i;
            if (x[i] > 0) si = i;
        }
        if (fi != -1 && si != -1) {
            int buff = x[fi];
            x[fi] = x[si];
            x[si] = buff;
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++)
            cout << a[x][y] << " ";
        cout << endl;
    }
    return 0;
}