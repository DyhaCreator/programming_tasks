#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n > k - 1 && (n - k + 1) % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
            cout << 1 << " ";
        cout << n - k + 1 << endl;
    } else if (n > k * 2 - 2 && (n - k * 2 + 2) % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
            cout << 2 << " ";
        cout << n - k * 2 + 2 << endl;
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