#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> l(n + 1, vector<int>(3, -1));
    for (int i = 1; i <= n; i++) {
        if (l[i - 1][0] != -1) l[i][0] = l[i - 1][0] + 1;
        if (l[i - 1][1] != -1) l[i][1] = l[i - 1][1] + 1;
        if (l[i - 1][2] != -1) l[i][2] = l[i - 1][2] + 1;
        l[i][s[i - 1] - 49] = 0;
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && l[i + 1][1] != -1 && l[i + 1][2] != -1) {
            ans = min(max(l[i + 1][1], l[i + 1][2]), ans);
        }
        if (s[i] == '2' && l[i + 1][0] != -1 && l[i + 1][2] != -1) {
            ans = min(max(l[i + 1][0], l[i + 1][2]), ans);
        }
        if (s[i] == '3' && l[i + 1][0] != -1 && l[i + 1][1] != -1) {
            ans = min(max(l[i + 1][0], l[i + 1][1]), ans);
        }
    }
    if (ans == INF) cout << 0 << endl;
    else cout << ans + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}