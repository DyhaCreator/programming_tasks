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
    sort(a.begin(), a.end());
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    cout << a[n / 2] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}