#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int index = n - 1;
    int found = 0;
    int first = 0;
    while (first < n && a[first] == '0')
        first++;
    // cout << first << endl;
    if (first == n) found = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '0' && b[i] == '1') {
            if (i < first) {
                found = 1;
            }
        }
        if (a[i] == '1' && b[i] == '0') {
            if (i < first) {
                found = 1;
            }
        }
    }
    if (a == b)
        found = 0;
    if (!found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}