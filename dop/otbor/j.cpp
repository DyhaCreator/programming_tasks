#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int l = 0;
    int r = 1000;
    for (int i = 0; i < 10; i++) {
        int m = (l + r) / 2;
        cout << "? 1 " << m << endl;
        int ans;
        cin >> ans;
        // cout << (ans == m) << endl;
        if (ans <= m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << "! " <<  r << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}