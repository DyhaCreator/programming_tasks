#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cout << "? " << 1 << " " << i + 1 << endl;
        cin >> a[i];
    }
    vector<int> s(n);
    if (a[n - 1] == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    int j = 0;
    while (a[j] == 0) j++;
    for (int i = 0; i < j - a[j]; i++)
        s[i] = 1;
    s[j] = 1;
    for (int i = j + 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            s[i] = 1;
        }
    }
    cout << "! ";
    for (auto &x : s)
        cout << x;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}