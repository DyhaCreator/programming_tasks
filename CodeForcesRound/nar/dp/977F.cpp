#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1);
    vector<int> pref(n + 1);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[mp[a[i] - 1]] + 1;
        pref[i + 1] = mp[a[i] - 1];
        mp[a[i]] = i + 1;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        if (dp[i + 1] > dp[mx + 1]) mx = i;
    cout << dp[mx + 1] << endl;
    int index = mx + 1;
    vector<int> ans = {};
    while (ans.size() < dp[mx + 1]) {
        ans.push_back(index);
        index = pref[index];
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}