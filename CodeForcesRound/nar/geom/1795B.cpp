#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> countL(52, 0);
    vector<int> countR(52, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        countL[a]++;
        countR[b]++;
    }
    if (countL[k] > 0 && countR[k] > 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}