#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int j = 0; j < k; j++) {
        int t;
        cin >> t;
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < t) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int ans = a[r];
        if (r > 0 && abs(t - ans) >= abs(t - a[r - 1])) {
            ans = a[r - 1];
        }
        cout << ans << endl;
    }
    return 0;
}