#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>p(n);
    for (auto &x : p)
        cin >> x;
    vector<int>pp = p;
    for (auto x : p) {
        pp.push_back(x);
    }
    n *= 2;
    /*for (auto x : pp)
        cout << x << " ";
    cout << endl;*/
    vector<vector<int>>dp(k + 1, vector<int>(n + 1));
    vector<vector<int>>dp2(k + 1, vector<int>(n + 1));
    for (int y = 1; y <= k; y++) {
        for (int x = 1; x <= n; x++) {
            if (y >= pp[x - 1] && dp[y - pp[x - 1]][x - 1] + pp[x - 1] <= y && dp[y - pp[x - 1]][x - 1] + pp[x - 1] > dp[y][x - 1]) {
                dp[y][x] = dp[y - pp[x - 1]][x - 1] + pp[x - 1];
                dp2[y][x] = 1;
            } else {
                dp[y][x] = dp[y][x - 1];
                dp2[y][x] = 0;
            }
            //cout << dp2[y][x] << " ";
        }
        //cout << endl;
    }
    if (dp[k][n] != k) {
        cout << "No" << endl;
        return 0;
    }
    vector<int>ans = {};
    int y = k, x = n;
    while (y > 0 && x > 0) {
        if (dp2[y][x] == 0) {
            x--;
        } else {
            ans.push_back(pp[x - 1]);
            y -= pp[x - 1];
            x--;
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}