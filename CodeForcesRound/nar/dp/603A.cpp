#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    for (int i = 0; i < n; i++)
        l[i + 1] = l[i] + (i == 0 || a[i] != a[i - 1]);
    for (int i = n - 1; i >= 0; i--)
        r[i] = r[i + 1] + (i == n - 1 || a[i] != a[i + 1]);
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
        dp[i + 1] = max(dp[i] + (i == 0 || a[i] != a[i - 1]), l[i] + (i == 0 || a[i] == a[i - 1]));
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            ans = max(ans, dp[i + 1] + r[i + 1]);
        } else {
            ans = max(ans, dp[i + 1] + max(r[i + 1] - 1, 0));
        }
    }
    cout << ans << endl;
    return 0;
}