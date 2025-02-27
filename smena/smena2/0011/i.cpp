#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1 << endl;
    } else if (n % 2 == 1) {
        for (int i = 1; i <= n; i+=2)
            cout << i << " ";
        cout << n - 3 << " " << n - 1 << " ";
        for (int i = n - 5; i >= 2; i-=2)
            cout << i << " ";
        cout << endl;
    } else if (n % 2 == 0) {
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
        cout << n - 3 << " " << n - 1 << " ";
        for (int i = n - 5; i >= 1; i -= 2)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}