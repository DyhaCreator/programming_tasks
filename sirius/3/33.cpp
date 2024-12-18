#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

const ll INF = 1e18 + 7;

int n, m;

void solve(vector<int> &a) {
    int t;
    cin >> t;
    int l = 0;
    int r = n;
    for (int i = 0; i < 5; i++) {
        int m = (l + r) / 2;
        // cout << l << " " << r << " " << m << endl;
        if (t > a[m]) {
            l = m;
        } else {
            r = m;
        }
    }
    // cout << endl;
    if (abs(a[l] - t) <= abs(a[r] - t)) {
        cout << a[l] << endl;
    } else {
        cout << a[r] << endl;
    }
    // cout << l << " " << r << endl;
}

int main() {
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    while (m--) solve(a);
    return 0;
}