#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> count(l + 1);
    for (auto &x : a) {
        for (int i = 0; i < l; i++) {
            if ((x & (1 << i)) > 0) {
                count[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++) {
        if (count[i] > n / 2) {
            ans = ans | (1 << i);
        }
    }
    cout << ans << endl;
    /*for (auto &x : count)
        cout << x << " ";
    cout << endl;*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}