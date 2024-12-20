#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int q;
    cin >> q;
    set<char> sym;
    map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < q; i++) {
        int l;
        char ch;
        cin >> l >> ch;
        sym.insert(ch);
        mp[ch].push_back({l, i});
    }
    for (auto &x : sym)
        sort(mp[x].begin(), mp[x].end());

    vector<int> ans_i(q);
    
    for (auto &ch : sym) {
        vector<int> l(n + 1);
        vector<int> r(n + 1);
        for (int i = 0; i < n; i++)
            if (a[i] == ch) l[i + 1] = l[i] + 1;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] == ch) r[i] = r[i + 1] + 1;
        vector<int> dpL0 = l;
        vector<int> dpR0 = r;
        vector<int> dpL1(n + 1);
        vector<int> dpR1(n + 1);

        vector<int> ans_dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dpR1[j - l[j]] = max(l[j] + dpR0[j + 1] + 1, dpR1[j - l[j]]);
                dpR1[j - dpL0[j]] = max(dpL0[j] + r[j + 1] + 1, dpR1[j - dpL0[j]]);
                dpR1[j] = max(dpR0[j + 1] + 1, dpR1[j]);

                dpL1[j + dpR0[j + 1] + 1] = max(l[j] + dpR0[j + 1] + 1, dpL1[j + dpR0[j + 1] + 1]);
                dpL1[j + r[j + 1] + 1] = max(dpL0[j] + r[j + 1] + 1, dpL1[j + r[j + 1] + 1]);
                dpL1[j + 1] = max(dpL0[j] + 1, dpL1[j + 1]);
            }
            int ans = 0;
            for (auto &x : dpL1)
                ans = max(ans, x);
            ans_dp[i] = ans;
            dpL0 = dpL1;
            dpR0 = dpR1;
        }
        for (auto &x : mp[ch])
            ans_i[x.second] = ans_dp[x.first - 1];
    }
    for (auto &x : ans_i)
        cout << x << endl;
    return 0;
}