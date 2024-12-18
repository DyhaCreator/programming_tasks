#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int last = 0;
    vector<int> b = {};
    for (auto &x : a) {
        if (x < last) {
            b.push_back(last - x);
        }
        last = max(last, x);
    }
    sort(b.begin(), b.end());
    /*for (auto &x : b)
        cout << x << " ";
    cout << endl;*/
    int pr = 0;
    ll ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans += (b[i] - pr) * (b.size() - i + 1);
        pr = b[i];
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}