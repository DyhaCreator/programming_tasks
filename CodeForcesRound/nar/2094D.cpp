#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a[0] != b[0]) {
        cout << "NO" << endl;
        return;
    }
    vector<int> c = {1};
    vector<int> d = {1};
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1]) {
            c[c.size() - 1]++;
        } else {
            c.push_back(1);
        }
    }
    for (int i = 1; i < b.size(); i++) {
        if (b[i] == b[i - 1]) {
            d[d.size() - 1]++;
        } else {
            d.push_back(1);
        }
    }
    if (c.size() != d.size()) {
        cout << "NO" << endl;
        return;
    }
    /*for (auto &x : c)
        cout << x << " ";
    cout << endl;
    for (auto &x : d)
        cout << x << " ";
    cout << endl;*/
    for (int i = 0; i < c.size(); i++) {
        if (c[i] > d[i] || c[i] * 2 < d[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}