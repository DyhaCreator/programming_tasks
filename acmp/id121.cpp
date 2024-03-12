#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = a[1] - a[0];
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]);
    }
    return 0;
}