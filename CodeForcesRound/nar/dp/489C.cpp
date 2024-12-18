#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, s;
    cin >> n >> s;
    if (n * 9 < s || (s == 0 && n > 1)) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    vector<vector<int>> dp(s + 2, vector<int>(n));
    dp[1][n - 1] = 1;
    for (int i = 2; i <= s; i++) {
        dp[i] = dp[i - 1];
        int index = 0;
        while (dp[i][index] == 9) index++;
        dp[i][index]++;
    }
    vector<vector<int>> dpmax(s + 2, vector<int>(n));
    for (int i = 1; i <= s; i++) {
        dpmax[i] = dpmax[i - 1];
        int index = 0;
        while (dpmax[i][index] == 9) index++;
        dpmax[i][index]++;
    }
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) cout << dp[s][i];
    cout << " ";
    for (int i = 0; i < n; i++) cout << dpmax[s][i];
    cout << endl;
    return 0;
}