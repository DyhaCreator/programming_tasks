#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; i++) {
        if (dp[i - 1] + abs(a[i] - a[i - 1]) < dp[i - 2] + abs(a[i] - a[i - 2]) * 3) {
            dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        } else {
            dp[i] = dp[i - 2] + abs(a[i] - a[i - 2]) * 3;
        }
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n - 1] << endl;
    return 0;
}