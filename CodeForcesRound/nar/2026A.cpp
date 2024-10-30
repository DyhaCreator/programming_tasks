#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    cout << "0 0 " << min(x, y) << " " << min(x, y) << endl;
    cout << 0 << " " << min(x, y) << " " << min(x, y) << " " << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}