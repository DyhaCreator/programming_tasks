#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    int last = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l - last >= s) {
            found = 1;
        }
        last = r;
    }
    if (m - last >= s)
        found = 1;
    cout << ((found)?"YES":"NO") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}