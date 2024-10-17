#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> dp(n * m + 1, vector<vector<int>>(n + 1, vector<int>(m + 1)));
    dp[1] = vector<vector<int>> (n + 1, vector<int>(m + 1, 1));

    for (auto &x : dp[1][0])
        x = 0;
    for (auto &x : dp[1])
        x[0] = 0;

    for (auto &x : dp) {
        for (auto &y : x) {
            for (auto &z : y) {
                cout << z << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}