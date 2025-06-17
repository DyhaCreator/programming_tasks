#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) {
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