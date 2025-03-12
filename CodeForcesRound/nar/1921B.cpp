#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt10 = 0;
    int cnt01 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') {
            cnt10++;
        } else if (a[i] == '0' && b[i] == '1') {
            cnt01++;
        }
    }
    cout << max(cnt10, cnt01) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}