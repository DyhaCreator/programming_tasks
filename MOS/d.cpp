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
        vector<int2>a = vector<int2>(b);
        for (auto &x : a) {
            cin >> x.x >> x.y;
        }
        vector<vector<int>>map = vector<vector<int>>(n, vector<int>(m, 0));
        for (auto x : a) {
            map[x.y - 1][x.x - 1] = 1;
        }
        /*for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cout << map[y][x] << " ";
            }
            cout << endl;
        }*/
        vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= m; x++) {
                if (dp[y - 1][x] > dp[y][x - 1]) {
                    dp[y][x] = dp[y - 1][x] + map[y - 1][x - 1];
                } else {
                    dp[y][x] = dp[y][x - 1] + map[y - 1][x - 1];
                }
                //cout << dp[y][x] << " ";
            }
            //cout << endl;
        }
        int ans = 0;
        int etalon = dp[n][m];
        //cout << etalon << endl;
        for (int i = 0; i < b; i++) {
            map[a[i].y - 1][a[i].x - 1] = 0;
            vector<vector<int>>dp2 = dp;
            for (int y = a[i].y; y <= n; y++) {
                for (int x = a[i].x; x <= m; x++) {
                    if (dp2[y - 1][x] > dp2[y][x - 1]) {
                        dp2[y][x] = dp2[y - 1][x] + map[y - 1][x - 1];
                    } else {
                        dp2[y][x] = dp2[y][x - 1] + map[y - 1][x - 1];
                    }
                    //cout << dp2[y][x] << " ";
                }
                //cout << endl;
            }
            if (dp2[n][m] < etalon) {
                ans++;
            }
            //cout << dp2[n][m] << endl;
            map[a[i].y - 1][a[i].x - 1] = 1;
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