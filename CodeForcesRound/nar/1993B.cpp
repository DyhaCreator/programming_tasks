#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int count1 = 0;
    int count2 = 0;
    ll max1 = -1;
    vector<int> odd = {};
    for (auto &x : a) {
        cin >> x;
        if (x % 2 == 0) count1++;
        if (x % 2 == 1) count2++;
        if (x % 2 == 0) odd.push_back(x);
        if (x % 2 == 1) max1 = max(max1, x);
    }
    if (count1 == 0 || count2 == 0) {
        cout << 0 << endl;
        return;
    }
    // cout << max1 << endl;
    sort(odd.begin(), odd.end());
    /*for (auto &x : odd)
        cout << x << " ";
    cout << endl;*/
    int found = 0;
    for (auto &x : odd) {
        if (max1 > x) {
            max1 += x;
        } else {
            found = 1;
            break;
        }
    }
    cout << count1 + found << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}