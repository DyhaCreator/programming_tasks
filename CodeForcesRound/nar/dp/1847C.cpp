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
    int save = n;
    for (int i = 0; i < 10; i++) {
        int xx = 0;
        int mx = 0;
        for (int j = n - 1; j >= 0; j--) {
            xx = xx ^ a[j];
            mx = max(mx, xx);
        }
        a.push_back(mx);
        n++;
    }
    int mx = 0;
    for (auto &x : a)
        mx = max(mx, x);
    cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}