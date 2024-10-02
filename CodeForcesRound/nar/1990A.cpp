#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mp(n + 1);
    for (auto &x : a) {
        cin >> x;
        mp[x]++;
    }
    for (auto &x : mp) {
        if (x != 0 && x % 2 == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}