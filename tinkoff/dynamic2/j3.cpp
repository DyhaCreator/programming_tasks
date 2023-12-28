#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> comp(vector<int>a) {
    vector<vector<int>>dp = vector<vector<int>>(a.size() + 1, vector<int>());
    dp[0] = {a[0]};
    for (int i = 1; i < a.size(); i++) {
        int indexMax = 0;
        for (int j = 0; j <= i; j++) {
            if (a[j] < a[i]) {
                if (dp[j].size() > dp[indexMax].size()) {
                    indexMax = j;
                }
            }
        }
        if (a[indexMax] < a[i]) {
            dp[i] = dp[indexMax];
            dp[i].push_back(a[i]);
        }
    }
    vector<int>ans = vector<int>();
    for (int i = 0; i < a.size(); i++) {
        if (dp[i].size() > ans.size()) {
            ans = dp[i];
        }
    }
    return ans;
}

vector<int> get(vector<int>a, vector<int>b, vector<vector<int>>dp, int x, int y) {
    vector<int>ans = vector<int>();
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
    return ans;
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
                if (get(a, b, dp, y - 1, x).size() > get(a, b, dp, y, x - 1).size()) {
                    dp[y][x] = dp[y - 1][x];
                } else {
                    dp[y][x] = dp[y][x - 1];
                }
                //dp[y][x] = std::max(dp[y - 1][x], dp[y][x - 1]);
            }
            //cout << dp[y][x] << " ";
        }
        //cout << endl;
    }
    vector<int>ans = get(a, b, dp, n, m);
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}