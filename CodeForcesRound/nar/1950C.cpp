#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    if (a == 0) {
        cout << 12 << ":" << ((b < 10)?"0":"") << b << " AM" << endl;
    } else if (a < 12) {
        cout << ((a < 10)?"0":"") << a << ":" << ((b < 10)?"0":"") << b << " AM" << endl;
    } else if (a == 12) {
        cout << a << ":" << ((b < 10)?"0":"") << b << " PM" << endl;
    } else {
        cout << ((a % 12 < 10)?"0":"") << a % 12 << ":" << ((b < 10)?"0":"") << b << " PM" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}