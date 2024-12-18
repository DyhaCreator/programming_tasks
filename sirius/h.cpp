#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = a[1] - a[0];
    for (int i = 2; i < n; i++) {
        int b = a[i] - a[i - 1];
        if (dp[i - 1] + b < dp[i - 2] + b || i == 2) {
            dp[i] = dp[i - 1] + b;
        } else {
            dp[i] = dp[i - 2] + b;
        }
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;*/
    cout << dp[n - 1] << endl;
    return 0;
}