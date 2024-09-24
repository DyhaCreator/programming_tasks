#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int mx = -INF;
    for (auto &x : a) {
        cin >> x;
        mx = max(mx, x);
    }
    for (int i = 0; i < m; i++) {
        char ch;
        int l, r;
        cin >> ch;
        cin >> l >> r;
        if (ch == '+') {
            if (mx >= l && mx <= r) mx++;
        } else {
            if (mx >= l && mx <= r) mx--;
        }
        cout << mx << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}