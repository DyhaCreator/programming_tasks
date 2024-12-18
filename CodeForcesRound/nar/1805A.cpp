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
    for (int k = 0; k < 256; k++) {
        int ans = 0;
        for (auto &x : a)
            ans = ans ^ (x ^ k);
        if (ans == 0) {
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}