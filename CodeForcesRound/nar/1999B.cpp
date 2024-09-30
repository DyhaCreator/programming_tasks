#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    vector<int> a(2);
    vector<int> b(2);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int ans = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i] > b[j] && a[i ^ 1] >= b[j ^ 1]) ans++;
            else if (a[i] >= b[j] && a[i ^ 1] > b[j ^ 1]) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}