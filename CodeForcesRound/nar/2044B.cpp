#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    for (auto &x : a) {
        if (x == 'q') {
            x = 'p';
        } else if (x == 'p') {
            x = 'q';
        }
    }
    cout << a << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}