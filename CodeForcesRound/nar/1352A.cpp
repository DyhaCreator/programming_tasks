#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n;
    cin >> n;
    vector<int> a = {};
    reverse(n.begin(), n.end());
    int st = 1;
    for (auto &x : n) {
        if (x != '0') a.push_back((x - '0') * st);
        st *= 10;
    }
    cout << a.size() << endl;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}