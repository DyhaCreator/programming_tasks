#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

vector<vector<int>>map;
int n, m;

void f(vector<vector<int>>&dp, int py, int px) {
    for (int y = 0; y <= py; y++) {
        for (int x = 0; x < m; x++) {
            if (y == py && x >= px) {
                break;
            }
            if (nod(map[py][px], map[y][x]) > 1 && dp[y][x] < dp[py][px]) {
                dp[py][px] = dp[y][x];
            }
        }
    }
    dp[py][px]++;
    if (py == 0 && px == 0) {
        dp[py][px] = 0;
    }
}

int main() {
    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<int>>dp = vector<vector<int>>(n, vector<int>(m, 1000000000));
    dp[0][0] = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            f(dp, y, x);
            //cout << dp[y][x] << " ";
        }
        //cout << endl;
    }
    if (dp[n - 1][m - 1] == 1000000001) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}

/*

3 3
6 9 5
8 6 21
77 14 11

*/