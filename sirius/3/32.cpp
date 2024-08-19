#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int solve(int q, vector<int> &a) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] <= q) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        cout << solve(q, a) << endl;
    }
    return 0;
}