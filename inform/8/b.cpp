#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    vector<int>dp = vector<int>(n + 1,INF);
    vector<int>pos = vector<int>(n + 1, 0);
    vector<int>prev = vector<int>(n + 1, 0);
    pos[0] = -1;
    int length = 0;
    dp[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
        if (dp[j - 1] < a[i] && dp[j] > a[i]) {
            dp[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = std::max(length, j);
        }
    }
    cout << length << endl;
    vector<int> ans = vector<int>();
    int p = pos[length];
    while (p != -1) {
        ans.push_back(a[p]);
        p = prev[p];
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}