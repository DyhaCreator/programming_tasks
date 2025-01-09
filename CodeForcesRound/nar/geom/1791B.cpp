#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int y = 0;
    int x = 0;
    for (auto &z : a) {
        if (z == 'U') y++;
        if (z == 'R') x++;
        if (z == 'D') y--;
        if (z == 'L') x--;
        if (y == 1 && x == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}