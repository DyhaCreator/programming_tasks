#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<int>v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        /*for (auto &x : v)
            cout << x << " ";
        cout << endl;*/
        vector<int>dp(n + 1);
        dp[0] = v[1];
        dp[1] = v[2];
        for (int i = 2; i < n; i++) {
            // dp[i] = min(dp[i - 1] + (v[i] - v[i - 1]), dp[i - 2] + (v[i] - v[i - 1]));
            dp[i] = std::min(dp[i - 1] + (v[i + 1] - v[i]) * a, dp[i - 2] + b);
            //cout << dp[i] << endl;
        }
        /*for (auto &x : dp)
            cout << x << " ";
        cout << endl;
        cout << dp[n - 1] << endl;*/
        if (dp[n - 1] >= f) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}