#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int ans = 0;
        int n, m, b;
        cin >> n >> m >> b;
        vector<vector<ll>>map(n + 1, vector<ll>(m + 1));
        vector<int2>v;
        int x, y;
        for (int j = 0; j < b; j++) {
            cin >> x >> y;
            map[x][y] = 1;
            v.push_back(int2(x, y));
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                map[j][k] = map[j][k] + max(map[j - 1][k], map[j][k - 1]);
            }
        }
        for (int l = 0; l < b; l++) {
            vector<vector<int>>newMap(n + 1, vector<int>(m + 1));
            for (int o = 0; o < b; o++) {
                newMap[v[o].x][v[o].y] = 1;
            }
            newMap[v[l].x][v[l].y] = 0;
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    newMap[j][k] = newMap[j][k] + max(newMap[j - 1][k], newMap[j][k - 1]);
                }
            }
            if (newMap[n][m] < map[n][m]) {
                ans++;
            }
            newMap[v[l].x][v[l].y] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}