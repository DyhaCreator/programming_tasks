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
    int ma = a[0];
    for (auto &x : a)
        ma = ma & x;
    if (ma != 0) {
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    int ta = a[0];
    for (int i = 0; i < n; i++) {
        ta = (ta & a[i]);
        // cout << ta << " ";
        if (ta == 0) {
            ans++;
            if (i < n - 1) ta = a[i + 1];
        }
    }
    // cout << endl;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}