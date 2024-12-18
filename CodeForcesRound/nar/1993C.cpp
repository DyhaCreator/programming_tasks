#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;*/
    int index = a[0];
    int indexEnd = a[0] + k;
    for (int i = 1; i < n; i++) {
        // cout << (index - a[i]) / k << endl;
        // cout << (index - a[i] + k - 1) / k * k + a[i] << endl;
        if ((index - a[i]) / k % 2 == 1) {
            index = (index - a[i] + k) / k * k + a[i];
            indexEnd = min((index - a[i] + k) / k * k + a[i] + k, indexEnd);
        } else {
            indexEnd = min((index - a[i] + k) / k * k + a[i], indexEnd);
        }
        // cout << index << " " << indexEnd << endl;
    }
    if (indexEnd - index > 0) {
        cout << index << endl;   
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}