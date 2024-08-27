#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int solve(int q, vector<int> &a) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < q) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (r > 0 && abs(a[r] - q) >= abs(a[r - 1] - q)) {
        cout << a[r - 1] << endl;
    } else {
        cout << a[r] << endl;
    }
    // cout << a[r] << " " << a[r - 1] << endl;
    return r;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        solve(q, a);
    }
    return 0;
}