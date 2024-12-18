#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int f(int i) {
    int ans = 0;
    while (i > 0) {
        ans += (i % 10) * (i % 10);
        i /= 10;
    }
    return ans;
}

int main() {
    int l;
    cin >> l;
    vector<int>m = vector<int>();
    m.push_back(0);
    m.push_back(1);
    for (int i = 2; i <= l; i++) {
        m.push_back(f(i));
        vector<vector<int>>dp = vector<vector<int>>(i + 1, vector<int>(i + 2, 0));
        for (int y = 1; y < i + 1; y++) {
            for (int x = 1; x < i + 2; x++) {
                if (y >= x - 1 && dp[y - (x - 1)][x] + m[x - 1] > dp[y][x - 1]) {
                    dp[y][x] = dp[y - (x - 1)][x] + m[x - 1];
                } else {
                    dp[y][x] = dp[y][x - 1];
                }
            }
        }
        m[i] = dp[i][i + 1];
    }
    cout << m[l] << endl;
    return 0;
}