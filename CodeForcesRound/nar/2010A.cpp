#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) sum += x;
        if (i % 2 == 1) sum -= x;
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}