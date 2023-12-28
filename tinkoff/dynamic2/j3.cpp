#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int>b = vector<int>(m);
    for (auto &x : b)
        cin >> x;
    vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int y = 1; y < n + 1; y++) {
        for (int x = 1; x < m + 1; x++) {
            if (a[y - 1] == b[x - 1]) {
                dp[y][x] = dp[y - 1][x - 1] + 1;
            } else {
                dp[y][x] = std::max(dp[y - 1][x], dp[y][x - 1]);
            }
            //cout << dp[y][x] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}