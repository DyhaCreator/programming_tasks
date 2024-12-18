#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x = 0;
    int y = 0;
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
        int n, m, b;
        cin >> n >> m >> b;
        vector<vector<int>>map = vector<vector<int>>(n, vector<int>(m));
        vector<int2>p = vector<int2>();
        for (int i = 0; i < b; i++) {
            int x, y;
            cin >> x >> y;
            p.push_back(int2(x - 1, y - 1));
            map[y - 1][x - 1] = 1;
        }
        vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= m; x++) {
                dp[y][x] = std::max(dp[y - 1][x], dp[y][x - 1]) + map[y - 1][x - 1];
            }
        }
        int etalon = dp[n][m];
        int ans = 0;
        for (int i = 0; i < b; i++) {
            map[p[i].y][p[i].x] = 0;

            vector<vector<int>>newdp = vector<vector<int>>(n + 1, vector<int>(m + 1));
            for (int y = 1; y <= n; y++) {
                for (int x = 1; x <= m; x++) {
                    newdp[y][x] = std::max(newdp[y - 1][x], newdp[y][x - 1]) + map[y - 1][x - 1];
                }
            }
            //cout << newdp[n][m] << endl;
            map[p[i].y][p[i].x] = 1;
            if (newdp[n][m] < etalon) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*

1
6 5 5
5 5
2 2
3 3
4 4
1 1

1
4 4 5
2 1
3 1
4 1
1 2
1 3

*/