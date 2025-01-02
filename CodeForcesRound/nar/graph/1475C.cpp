#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> m(k);
    vector<int> w(k);
    for (auto &x : m)
        cin >> x;
    for (auto &x : w)
        cin >> x;
    vector<vector<int>> fm(a);
    vector<vector<int>> fw(b);
    for (int i = 0; i < k; i++) {
        fm[m[i] - 1].push_back(w[i] - 1);
        fw[w[i] - 1].push_back(m[i] - 1);
    }
    ll ans = 0;
    for (int i = 0; i < a; i++) {
        for (auto &x : fm[i]) {
            ans += k - fw[x].size() - fm[i].size() + 1;
        }
    }
    cout << ans / 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}