#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int x, y;
    cin >> x >> y;
    if (y > x && y - x == 1) {
        cout << "YES" << endl;
    } else if (y < x && (x - y + 1) % 9 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}