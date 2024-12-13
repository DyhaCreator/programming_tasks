#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int index = n - 1;
    while (index > 0 && a[index] >= a[index - 1]) index--;
    int ans = 0;
    for (int i = 0; i < index; i++) {
        if (a[i] > x) {
            int buff = x;
            x = a[i];
            a[i] = buff;
            ans++;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}