#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while (a != 0 && b != 0) {
        if (a < b) {
            ans += b / a;
            b -= (b / a) * a;
        } else {
            ans += a / b;
            a -= (a / b) * b;
        }
    }
    cout << ans << endl;
    return 0;
}