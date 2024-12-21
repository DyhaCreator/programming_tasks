#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.S == b.S) return a.F < b.F;
    return a.S < b.S;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    sort(a.begin(), a.end(), comp);
    vector<int> dp(n);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = i;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m].S < a[i].F) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (r > 0 && a[i].F <= a[r].S) r--;
        if (a[i].F <= a[r].S) {
            dp[i] = 1;
        } else {
            dp[i] = pref[r + 1] + 1;
        }
        pref[i + 1] = max(pref[i], dp[i]);
    }
    cout << pref[n] << endl;
    return 0;
}