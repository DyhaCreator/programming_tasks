#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    for (int i = 0; i < k; i++) {
        cout << n - k + i + 1 << " ";
    }
    for (int i = k; i < n; i++) {
        cout << n - i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}