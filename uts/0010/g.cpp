#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int m;

void rec(vector<int> &a, int sum, int len, set<int> &w1) {
    if (len == a.size()) {
        w1.insert(sum);
        return;
    }
    rec(a, sum, len + 1, w1);
    sum = (sum + a[len]) % m;
    rec(a, sum, len + 1, w1);
}

int main() {
    int n;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> a1 = {};
    vector<int> a2 = {};
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            a1.push_back(a[i]);
        } else {
            a2.push_back(a[i]);
        }
    }
    set<int> w1;
    set<int> w2;
    rec(a1, 0, 0, w1);
    rec(a2, 0, 0, w2);
    int ans = 0;
    vector<int> b1 = {};
    vector<int> b2 = {};
    for (auto &x : w1)
        b1.push_back(x);
    for (auto &x : w2)
        b2.push_back(x);
    for (auto &x : b1) {
        int l = 0;
        int r = b2.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (x + b2[mid] < m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        r = max(r - 1, 0);
        ans = max(ans, (x + b2[r]) % m);
        l = 0;
        r = b2.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (x + b2[mid] < 2 * m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        r = max(r - 1, 0);
        ans = max(ans, (x + b2[r]) % m);
    }
    cout << ans << endl;
    return 0;
}