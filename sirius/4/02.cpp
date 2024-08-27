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
        // cout << r << " " << a[r] << endl;
        if (r < n && a[r] == t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}