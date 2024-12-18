#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    vector<ll>dp(n);
    dp[0] = a[1] - a[0];
    dp[1] = a[2] - a[0];
    for (int i = 2; i < n; i++) {
        dp[i] = std::min(dp[i - 1] + (a[i + 1] - a[i]), dp[i - 2] + (a[i + 1] - a[i]));
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n - 2] << endl;
    return 0;
}