#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int mw = 0;
    int  mh = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mw = max(mw, x);
        mh = max(mh, y);
    }
    cout << mh * 2 + mw * 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}