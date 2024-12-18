#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a, b;
    cin >> a >> b;
    int index = 0;
    int n = a.size();
    int m = b.size();
    for (auto &x : a) {
        if (index < m) {
            if (x == '?') x = b[index];
            if (x == b[index]) index++;
        }
    }
    if (index == m) {
        cout << "YES" << endl;
        for (auto &x : a)
            cout << ((x == '?')?'a':x);
        cout << endl;
    } else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}