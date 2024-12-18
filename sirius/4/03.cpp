#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < k; i++) {
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
        if (a[r] != t) {
            cout << 0 << endl;
            continue;
        }
        int save_r = r;

        l = 0;
        r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] <= t) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << save_r + 1 << " " << r << endl;
    }
    return 0;
}