#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    if ((n + s - 1) / s == (n + x - 1) / x) {
        cout << "Tie" << endl;
    } else if ((n + s - 1) / s > (n + x - 1) / x) {
        cout << "Monkey" << endl;
    } else {
        cout << "Tortoise" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}