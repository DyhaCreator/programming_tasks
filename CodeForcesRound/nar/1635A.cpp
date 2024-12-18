#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    ll a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a = a | x;
    }
    cout << a << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}