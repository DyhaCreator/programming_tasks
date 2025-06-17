#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    set<int> b;
    for (int i = 0; i < n - 3; i++) {
        if (a[i] == '1' && a[i + 1] == '1' && a[i + 2] == '0' && a[i + 3] == '0')
            b.insert(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        a[x] = y + '0';
        if (y == 0) {
            b.erase(x);
            b.erase(x - 1);
        } else {
            b.erase(x - 2);
            b.erase(x - 3);
        }

        if (x < n - 3 && a[x] == '1' && a[x + 1] == '1' && a[x + 2] == '0' && a[x + 3] == '0')
            b.insert(x);
        if (x >= 1 && x < n - 2 && a[x - 1] == '1' && a[x] == '1' && a[x + 1] == '0' && a[x + 2] == '0')
            b.insert(x - 1);
        if (x >= 2 && x < n - 1 && a[x - 2] == '1' && a[x - 1] == '1' && a[x] == '0' && a[x + 1] == '0')
            b.insert(x - 2);
        if (x >= 3 && a[x - 3] == '1' && a[x - 2] == '1' && a[x - 1] == '0' && a[x] == '0')
            b.insert(x - 3);

        
        
        if (b.size() > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}