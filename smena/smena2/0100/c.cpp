#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool comp(pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
    return a.F.size() < b.F.size();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int>> a(m);
    for (auto &x : a) {
        int c;
        cin >> c;
        for (int i = 0; i < c; i++) {
            int y;
            cin >> y;
            x.F.push_back(y);
        }
        sort(x.F.begin(), x.F.end());
    }
    for (int i = 0; i < m; i++)
        a[i].S = i;
    sort(a.begin(), a.end(), comp);
    /*for (auto &x : a) {
        for (auto &y : x.F)
            cout << y << " ";
        cout << endl;
    }*/
    vector<int> cnt(n);
    vector<int> ans(m);
    for (auto &x : a) {
        int index = 0;
        while (index < x.F.size() && cnt[x.F[index] - 1] == (m + 1) / 2)
            index++;
        if (index == x.F.size()) {
            cout << "NO" << endl;
            return;
        }
        cnt[x.F[index] - 1]++;
        ans[x.S] = x.F[index];
    }
    cout << "YES" << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}