#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp1(n);
    vector<int> dp2(n);
    dp1[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            dp1[i] = dp1[i - 1] + 1;
            dp2[i] = dp2[i - 1] + 1;
        } else {
            dp1[i] = 1;
        }
        if (i >= 2 && a[i - 2] < a[i]) dp2[i] = max(dp2[i], dp1[i - 2] + 1);
        dp2[i] = max(dp2[i], dp1[i]);
    }
    int ans = 0;
    for (auto &x : dp2)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}