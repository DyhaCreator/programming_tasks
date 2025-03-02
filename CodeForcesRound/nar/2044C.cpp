#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int f = min(a, m);
    int s = min(b, m);
    cout << f + s + min(2 * m - f - s, c) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}