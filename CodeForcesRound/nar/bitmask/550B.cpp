#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        int mn = INF;
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) > 0) {
                sum += a[j];
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
            }
        }
        if (sum >= l && sum <= r && mx - mn >= x) ans++;
    }
    cout << ans << endl;
    return 0;
}