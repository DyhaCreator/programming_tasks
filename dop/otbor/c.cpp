#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (auto &x : mp)
        cin >> x;
    /*for (auto &x : mp)
        cout << x << endl;*/
    ll x = -1, y = -1;
    ll count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#') {
                if (x == -1 && y == -1) {
                    x = i;
                    y = j;
                } else {
                    x += i;
                    y += j;
                    count++;
                }
            }
        }
    }
    cout << x / count + 1 << " " << y / count + 1 << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}