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
        int n, m, b;
        cin >> n >> m >> b;
        vector<vector<int>>map(n + 1, vector<int>(m + 1));
        vector<int2>v(b);
        for (int j = 0; j < b; j++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
            v[j] = int2(x, y);
        }
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= m; x++) {
                dp[y][x] = std::max(dp[y - 1][x], dp[y][x - 1]) + map[y][x];
            }
        }
        //cout << dp[n][m] << endl;
        int ans = 0;
        for (int j = 0; j < b; j++) {
            map[v[j].y][v[j].x] = 0;

            vector<vector<int>>dp2(n + 1, vector<int>(m + 1));
            for (int y = 1; y <= n; y++) {
                for (int x = 1; x <= m; x++) {
                    dp2[y][x] = std::max(dp2[y - 1][x], dp2[y][x - 1]) + map[y][x];
                    //cout << map[y - 1][x - 1] << " ";
                }
                //cout << endl;
            }
            //cout << dp2[n][m] << endl;
            if (dp2[n][m] < dp[n][m]) {
                ans++;
            }
            map[v[j].y][v[j].x] = 1;
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