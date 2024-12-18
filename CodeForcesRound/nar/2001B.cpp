#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> a(n);
    int id = 0;
    for (int i = n / 2; i < n; i++) {
        a[i] = id;
        id += 2;
    }
    id = 1;
    for (int i = n / 2; i >= 0; i--) {
        a[i] = id;
        id += 2;
    }
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}