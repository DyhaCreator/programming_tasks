#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int >> dp = vector<vector<int >> (s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 0; i <= s2.size(); i++) {
        dp[0][i] = i;
    }
    for (int i = 0; i <= s1.size(); i++) {
        dp[i][0] = i;
    }
    for (int y = 1; y <= s1.size(); y++) {
        for (int x = 1; x <= s2.size(); x++) {
            if (s1[y - 1] == s2[x - 1]) {
                dp[y][x] = dp[y - 1][x - 1];
            } else {
                dp[y][x] = min(dp[y][x - 1] + 1, min(dp[y - 1][x - 1] + 1, dp[y - 1][x] + 1));
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}