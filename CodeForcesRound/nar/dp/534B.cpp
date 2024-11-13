#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    int t, d;
    cin >> t >> d;
    vector<int> dp(t);
    dp[0] = a;
    for (int i = 1; i < t; i++)
        dp[i] = min(a + d * i, b + d * (t - i - 1));
    int ans = 0;
    for (auto &x : dp)
        ans += x;
    cout << ans << endl;
    return 0;
}