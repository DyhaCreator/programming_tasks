#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator<(const int2 &o)  const {
        if (this->x == o.x) {
            return this->y < o.y;
        }
        return this->x < o.x;
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
        //map<int2, int>mp;
        vector<int2>v;
        int x, y;
        for (int j = 0; j < b; j++) {
            cin >> x >> y;
            map[x][y] = 1;
            v.push_back(int2(x, y));
        }
        //vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        vector<int>dp1(m + 1, 0);
        vector<int>dp2(m + 1, 0);
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                dp2[k] = map[j][k] + max(dp1[k], dp2[k - 1]);
                //dp[j][k] = map[j][k] + max(dp[j - 1][k], dp[j][k - 1]);
                //map[j][k] = map[j][k] + max(map[j - 1][k], map[j][k - 1]);
            }
            dp1 = dp2;
        }
        //cout << dp2[m] << endl;
        int en = dp2[m];
        for (int l = 0; l < b; l++) {
            /*vector<vector<int>>newMap(n + 1, vector<int>(m + 1));
            for (int o = 0; o < b; o++) {
                newMap[v[o].x][v[o].y] = 1;
            }*/
            map[v[l].x][v[l].y] = 0;
            dp1 = vector<int>(m + 1, 0);
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    dp2[k] = map[j][k] + max(dp1[k], dp2[k - 1]);
                }
                dp1 = dp2;
            }
            if (dp2[m] < en) {
                ans++;
            }
            map[v[l].x][v[l].y] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}