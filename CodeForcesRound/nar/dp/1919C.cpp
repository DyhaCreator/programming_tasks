#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> b = {a[0]};
    
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            b.push_back(a[i]);
        }
    }
    a = b;
    n = b.size();

    a.push_back(0);
    vector<pair<int, int>> dpCount(n + 2);
    vector<pair<int, int>> dpLast(n + 2);
    dpLast[0] = {0, 0};
    dpLast[1] = {a[0], 0};

    for (int i = 2; i <= n + 1; i++) {
        int l1 = dpCount[i - 1].F + (dpLast[i - 1].F < a[i - 1]);
        int r1 = dpCount[i - 1].S;
        int l2 = dpCount[i - 2].F + (dpLast[i - 2].F != 0 && dpLast[i - 2].F < a[i - 1]);
        int r2 = (dpLast[i - 1].S != 0 && dpLast[i - 1].S < a[i - 2]);
        // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        if (l1 + r1 <= l2 + r2) {
            dpCount[i] = {l1, r1};
            dpLast[i] = {a[i - 1], dpLast[i - 1].S};
        } else {
            dpCount[i] = {l2, r2};
            dpLast[i] = {a[i - 1], a[i - 2]};
        }
    }

    /*for (auto &x : dpCount)
        cout << x.first << " ";
    cout << endl;
    for (auto &x : dpCount)
        cout << x.second << " ";
    cout << endl;
    for (auto &x : dpLast)
        cout << x.first << " ";
    cout << endl;
    for (auto &x : dpLast)
        cout << x.second << " ";
    cout << endl;*/
    cout << dpCount[n + 1].F + dpCount[n + 1].S << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}