#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > a && c > b) {
        cout << "STAIR" << endl;
    } else if (b > a && b > c) {
        cout << "PEAK" << endl;
    } else {
        cout << "NONE" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}