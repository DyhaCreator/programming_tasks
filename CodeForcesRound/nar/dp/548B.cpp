#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    vector<int> mx(n);
    for (int i = 0; i < n; i++) {
        vector<int> pref(m + 1);
        int mnx = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) pref[j + 1] = pref[j] + 1;
            mnx = max(mnx, pref[j + 1]);
        }
        mx[i] = mnx;
    }
    while (q--) {
        int y, x;
        cin >> y >> x;
        y--;x--;
        a[y][x] = 1 - a[y][x];
        vector<int> pref(m + 1);
        int mnx = 0;
        for (int j = 0; j < m; j++) {
            if (a[y][j] == 1) pref[j + 1] = pref[j] + 1;
            mnx = max(mnx, pref[j + 1]);
        }
        mx[y] = mnx;
        mnx = 0;
        for (auto &x : mx)
            mnx = max(mnx, x);
        cout << mnx << endl;
    }
    return 0;
}