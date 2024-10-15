#include <iostream>
#include <vector>
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
    vector<int> b(n);
    for (auto &x : b)
        cin >> x;
    int m;
    cin >> m;
    vector<int> d(m);
    for (auto &x : d)
        cin >> x;
    map<int, int> mp;
    for (auto &x : d)
        mp[x]++;
    /*for (auto &x : d)
        cout << mp[x] << " ";
    cout << endl;*/
    for (int i = 0; i < n; i++) {
        // cout << a[i] << " " << b[i] << " " << mp[b[i]] << endl;
        if (a[i] != b[i] && mp[b[i]] > 0) mp[b[i]]--;
        else if (a[i] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    int found = 0;
    for (auto &x : b) {
        if (d.back() == x) {
            found = 1;
            break;
        }
    }
    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}