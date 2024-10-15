#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    int saveM = m;
    int ans1 = 0;
    int y = 0;
    m = min(n, m);
    while (m > 0 && n != 0) {
        // cout << ((1 << y) & n) << endl;
        if (((1 << y) & n) == 0)
            ans1 = ans1 | (1 << y);
        else {
            m -= (1 << y);
        }
        y++;
    }
    m = saveM;
    int ans2 = n;
    y = 0;
    while (y < 31) {
        if (!(n & (1 << y)) && ((n + m) & (1 << y))) {
            ans2 = ans2 | ((1 << (y + 1)) - 1);
        }
        // cout << (n & (1 << y)) << " " << ((n + m) & (1 << y)) << endl;
        y++;
    }
    ans1 = ans1 | n;
    /*cout << ans1 << endl;
    cout << ans2 << endl;*/
    cout << (ans1 | ans2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}