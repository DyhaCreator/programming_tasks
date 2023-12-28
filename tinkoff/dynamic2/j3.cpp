#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool comp(vector<int>a, vector<int>b) {
    vector<int>dp1 = vector<int>(a.size() + 1);
    return true;
}

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
    vector<int>ans = vector<int>();
    int y = n, x = m;
    while (y > 0 && x > 0) {
        if (a[y - 1] == b[x - 1]) {
            ans.push_back(a[y - 1]);
            y--;
            x--;
        } else {
            if (dp[y - 1][x] > dp[y][x - 1]) {
                y--;
            } else {
                x--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}