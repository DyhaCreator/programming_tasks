#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<pair<int, int>, int>> a(n);
    vector<int> cnt(26);
    for (auto &x : s)
        cnt[x - 'a']++;
    for (int i = 0; i < n; i++)
        a[i] = {{cnt[s[i] - 'a'], s[i] - 'a'}, i};
    sort(a.begin(), a.end());
    vector<pair<pair<int, int>, int>> b = a;
    /*for (int i = 0; i < n; i++)
        b[i] = a[i];*/
    reverse(b.begin(), b.end());
    int l = 0;
    int r = n - 1;
    for (auto &x : b) {
        if (a[l].F.S != x.F.S) {
            a[l].F.S = x.F.S;
            l++;
        } else if (a[r].F.S != x.F.S) {
            a[r].F.S = x.F.S;
            r--;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[a[i].S] = a[i].F.S;
    for (auto &x : ans)
        cout << char(x + 'a');
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}