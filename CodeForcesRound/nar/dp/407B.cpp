#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> dp(n + 1);
    for (int i = 1; i <= n; i++)
        dp[i] = (((dp[i - 1] + 1) * 2) - ((a[i - 1] > 1)?dp[a[i - 1] - 1]:0) + INF) % INF;
    cout << dp[n] << endl;
    return 0;
}