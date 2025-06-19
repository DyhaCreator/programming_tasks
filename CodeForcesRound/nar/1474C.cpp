#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    set<int> st;
    for (auto &x : a)
        st.insert(x);
    vector<int> ind(1000001, -1);
    vector<int> b = {};
    for (auto &x : st) {
        ind[x] = b.size();
        b.push_back(x);
    }
    vector<int> used(b.size());
    for (auto &x : a)
        used[ind[x]]++;
    /*for (auto &x : b)
        cout << x << " ";
    cout << endl;
    for (auto &x : used)
        cout << x << " ";
    cout << endl;*/
    int f = 0;
    for (int i = 0; i < b.size() - (used[b.size() - 1] == 1); i++) {
        vector<int> c = b;
        vector<int> d = used;
        int mx = c.size() - 1;
        vector<pair<int, int>> ans = {{c[mx], c[i]}};
        d[mx]--;
        d[i]--;
        int sum = c[mx];
        int fz = 0;
        for (int i = 0; i < n / 2 - 1; i++) {
            while (d[mx] == 0 && mx >= 0) mx--;
            d[mx]--;
            if (d[ind[sum - c[mx]]] == 0 || ind[sum - c[mx]] == -1) {
                fz = 1;
                break;
            }
            d[ind[sum - c[mx]]]--;
            ans.push_back({c[mx], sum - c[mx]});
            sum = c[mx];
        }
        if (fz == 0) {
            f = 1;
            cout << "YES" << endl;
            cout << ans[0].F + ans[0].S << endl;
            for (auto &x : ans)
                cout << x.F << ' ' << x.S << endl;
            return;
        }
    }
    if (f == 0) {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}