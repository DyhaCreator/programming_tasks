#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    sort(a.begin(), a.end());
    vector<int> dp(n);
    for (int i = 1; i < n; i++) {
        int l = 0;
        int r = i;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[i].F - a[m].F > a[i].S) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        dp[i] = dp[max(r - 1, 0)] + (i - r);
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[i] + (n - i - 1));
    cout << ans << endl;
    return 0;
}