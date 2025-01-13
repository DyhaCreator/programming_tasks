#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int ans = INF;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " " << a[l] + (double)(a[r] - a[l]) / (r - l) * (i - l) << "  ";
                if (a[i] != a[l] + (double)(a[r] - a[l]) / (r - l) * (i - l))
                    sum++;
            }
            cout << endl;
            cout << sum << endl;
            ans = min(ans, sum);
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