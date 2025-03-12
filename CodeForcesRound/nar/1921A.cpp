#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x0, y0;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x0 = min(min(x0, x1), min(x2, x3));
    y0 = min(min(y0, y1), min(y2, y3));
    x1 = max(max(x0, x1), max(x2, x3));
    y1 = max(max(y0, y1), max(y2, y3));
    cout << (x1 - x0) * (y1 - y0) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}