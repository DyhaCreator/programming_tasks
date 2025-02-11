#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> cnt(2000);
    for (auto &x : a)
        cnt[x]++;
    for (int i = 1; i < 2000 - 1; i++) {
        if (cnt[i] == 1) {
            cout << "NO" << endl;
            return;
        }
        if (cnt[i] > 0) {
            cnt[i + 1] += cnt[i] - 2;
            cnt[i] = 2;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}