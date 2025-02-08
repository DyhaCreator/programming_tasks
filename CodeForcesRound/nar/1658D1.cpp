#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> cnt((1 << 17) + 1, 0);

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (auto &x : a)
        cnt[x] = 1;
    for (auto &x : a) {
        if (cnt[(x ^ (r + 1))] == 0 && cnt[x ^ r] == 1) {
            cout << x << endl;
            for (auto &x : a)
                cnt[x] = 0;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}