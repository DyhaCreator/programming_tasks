#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector<int>a = vector<int>(n);
    a[0] = a1;
    for (int i = 1; i < n; i++) {
        a[i] = (k * a[i - 1] + b) % m;
    }
    vector<int>dp = vector<int>(n + 1, m + 1);
    vector<int>pos = vector<int>(n + 1, 0);
    vector<int>prev = vector<int>(n + 1, 0);
    pos[0] = -1;
    int length = 0;
    dp[0] = -(m + 1);
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
        if (dp[j - 1] < a[i] && dp[j] > a[i]) {
            dp[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = std::max(length, j);
        }
    }
    vector<int> ans = vector<int>();
    int p = pos[length];
    while (p != -1) {
        ans.push_back(a[p]);
        p = prev[p];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}