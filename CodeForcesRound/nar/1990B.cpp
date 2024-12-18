#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    y--;
    vector<int> ans(n, 1);
    int count = 0;
    for (int i = x; i < n; i++) {
        if (count % 2 == 0) ans[i] = -1;
        count++;
    }
    count = 0;
    for (int i = y - 1; i >= 0; i--) {
        if (count % 2 == 0) ans[i] = -1;
        count++;
    }
    
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