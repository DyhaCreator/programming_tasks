#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a = {};
    for (auto &x : s)
        a.push_back(x - '0');
    int l = 0;
    int last = 0;
    for (auto &x : a) {
        if (x != last) l++;
        last = x;
    }
    if (l == 0) {
        cout << n + (a[0] == 1) << endl;
    } else if (l == 1 || l == 2) {
        cout << n + 1 << endl;
    } else {
        cout << n + l - 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}