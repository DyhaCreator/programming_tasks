#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int mx = 0;
    int lastMx = 0;
    for (auto &x : a)
        mx = max(mx, x);
    for (auto &x : a)
        if (x < mx) lastMx = max(lastMx, x);
    int found = 0;
    a.push_back(INF);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == mx && (a[i + 1] == mx || a[i + 2] == mx)) {
            found = 1;
        }
    }
    if (found) {
        cout << mx << endl;
    } else {
        cout << lastMx << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}