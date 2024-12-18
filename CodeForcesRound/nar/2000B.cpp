#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int l = -1, r = -1;
    int found = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (l == -1) {
            l = x;
            r = x;
        }
        if (found) continue;
        if (x != l && x != r) {
            cout << "NO" << endl;
            found = 1;
            continue;
        }
        if (x == l) l--;
        if (x == r) r++;
    }
    if (!found) cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}