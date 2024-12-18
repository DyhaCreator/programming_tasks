#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    set<int> st1;
    for (auto &x : a)
        st1.insert(x);
    map<int, int> count;
    for (auto &x : a)
        count[x]++;
    vector<int> st = {};
    for (auto &x : st1)
        st.push_back(x);
    int m = st.size();
    vector<int> lst(m + 1);
    for (int i = 1; i <= m; i++) {
        if (st[i - 1] == i - 1) {
            lst[i] = i;
        } else {
            lst[i] = lst[i - 1];
        }
    }

    vector<vector<int>> dp(m, vector<int>(m + 1, 0));
    for (int i = 0; i < m; i++)
        dp[0][i + 1] = dp[0][i] + lst[i + 1] * (count[st[i]] - 1) + lst[i];

    for (int i = 1; i < m; i++) {
        for (int j = i; j < m; j++) {
            dp[i][j + 1] = dp[0][j - i] + lst[j + 1] * (count[st[j - i]] - 1) + lst[j - i];
        }
    }

    int ans = INF;
    for (auto &x : dp)
        ans = min(ans, x.back());
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}