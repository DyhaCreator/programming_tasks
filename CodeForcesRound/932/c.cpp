#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;


int solve() {
    cin >> n >> l;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}