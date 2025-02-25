#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = a[i + 1] - a[i];
    for (auto &x : b)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}