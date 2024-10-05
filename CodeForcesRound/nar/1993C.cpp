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
    int indexStart = a[0];
    for (int i = 1; i < n; i++) {
        int c = (index - a[i]) / (2*k) * 2*k + a[i];
        if (c != index) {
            if ((index - a[i]) / k % 2 == 1) { 
                c += 2 * k;
            }
        }
        // cout << c << endl;
        index = max(index, c);
        // cout << index << endl;
    }
    cout << index << " " << indexStart << endl;
    if (index < indexStart + k) {
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