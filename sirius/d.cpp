#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; i - j <= 3 && j >= 0; j--) {
            dp[i] += dp[j];
        }
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n] << endl;
    return 0;
}