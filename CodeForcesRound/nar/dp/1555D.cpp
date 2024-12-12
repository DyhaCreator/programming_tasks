#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void rec(vector<string> &st, string b) {
    if (b.size() == 3) {
        int cnt = 0;
        for (auto &x : b) if (x == 'a') cnt++;
        if (cnt != 1) return;
        cnt = 0;
        for (auto &x : b) if (x == 'b') cnt++;
        if (cnt != 1) return;
        cnt = 0;
        for (auto &x : b) if (x == 'c') cnt++;
        if (cnt != 1) return;
        st.push_back(b);
        return;
    }
    b.push_back('a');
    rec(st, b);
    b[b.size() - 1] = 'b';
    rec(st, b);
    b[b.size() - 1] = 'c';
    rec(st, b);
}

int main() {
    int n, m;
    cin >> n >> m;
    string a;
    cin >> a;
    vector<string> st = {};
    rec(st, "");
    vector<string> str = {};
    for (auto &x : st) {
        for (int c = 0; c < 3; c++) {
            str.push_back("");
            for (int i = 0; i < n; i++) {
                str[str.size() - 1].push_back(x[(i + c) % 3]);
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (str.size()));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < str.size(); j++) {
            dp[i + 1][j] = dp[i][j] + (str[j][i] != a[i]);
        }
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int ans = INF;
        for (int j = 0; j < str.size(); j++) {
            ans = min(ans, dp[r][j] - dp[l - 1][j]);
        }
        cout << ans << endl;
    }
    
    return 0;
}