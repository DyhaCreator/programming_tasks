#include <algorithm>
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
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = i + a[i];
    sort(b.begin(), b.end());
    for (auto &x : b)
        cout << x << " ";
    cout << endl;
    for (int i = 1; i < n; i++) {
        if (b[i] - b[i - 1] != 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}