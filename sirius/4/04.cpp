#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (a[m] < a[i] + a[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += r - 1 - j;
            // cout << i << " " << j << " " << r << " " << r - (j + 1) << endl;
        }
    }
    cout << ans << endl;
    return 0;
}