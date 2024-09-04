#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll x, k;
    cin >> x >> k;
    int ans = 0;
    while (x < 1000000000) {
        x *= k;
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}