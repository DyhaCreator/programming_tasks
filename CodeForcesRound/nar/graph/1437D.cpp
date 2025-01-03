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
    vector<int> b = {};
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (a[i - 1] < a[i]) {
            cnt++;
        } else {
            b.push_back(cnt);
            cnt = 0;
        }
    }
    for (auto &x : b)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}