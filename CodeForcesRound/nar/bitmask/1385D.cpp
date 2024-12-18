#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
string s;
int n;
int ans = INF;

void gen(int l, int r, int c, char ch) {
    if (r - l <= 1) {
        if (s[l] != ch) c++;
        // cout << l << " " << r << " " << c << " " << ch << endl;
        ans = min(ans, c);
        return;
    }
    int m = (l + r) / 2;
    int lc = 0;
    for (int i = l; i < m; i++) {
        if (s[i] != ch) {
            lc++;
        }
    }
    int rc = 0;
    for (int i = m; i < r; i++) {
        if (s[i] != ch) {
            rc++;
        }
    }
    gen(l, m, c + rc, ch + 1);
    gen(m, r, c + lc, ch + 1);
    // cout << lc << " " << rc << endl;
}

void solve() {
    cin >> n;
    cin >> s;
    ans = INF;
    gen(0, n, 0, 'a');
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}