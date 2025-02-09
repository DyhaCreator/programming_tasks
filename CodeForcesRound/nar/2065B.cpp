#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a;
    cin >> a;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1]) {
            cout << 1 << endl;
            return;
        }
    }
    cout << a.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}