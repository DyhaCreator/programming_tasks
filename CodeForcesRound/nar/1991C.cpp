#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> ans = {};
    int found = 0;
    for (int i = 0; i <= 40; i++) {
        int mx = -1;
        for (auto &x : a)
            mx = max(mx, x);
        if (mx == 0) {
            found = 1;
            break;
        }
        mx = (mx + 1) >> 1;
        ans.push_back(mx);
        for (auto &x : a)
            x = abs(x - mx);

        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
    }
    if (!found) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}