#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll x, y, k, l;
    cin >> x >> y >> k >> l;
    ll my = max(x, y);
    ll mx = min(x, y);
    x = mx;
    y = my;
    ll n = 0;
    while (n * k + x < k)
        n++;
    x += n * k;
    y += n * k;
    if (x == y && min(abs(y / k * k - x), abs(((x + k - 1) / k) * k - y)) > l) {
        cout << 1 << endl;
        return 0;
    }
    ll col = (y / k * k - ((x + k - 1) / k) * k) / k * ((k - 1) / (l * 2));
    if (y / k * k > x && ((x + k - 1) / k) * k < y) {
        col += (((((x + k - 1) / k) * k - l - x) + l * 2 - 1) / (l * 2));
        col += ((y - (y / k * k + l) + l * 2 - 1) / (l * 2));
        cout << col << endl;
    } else {
        // cout << min(y, ((x + k) / k) * k - l) << endl;
        // cout << max(x, (y - 1) / k * k + l) << endl;
        cout << ((min(y, ((x + k) / k) * k - l) - max(x, (y - 1) / k * k + l) + l * 2 - 1) / (l * 2)) << endl;
    }
    // cout << (y / k * k - ((x + k - 1) / k) * k) / k * ((k - 1) / (l * 2)) << endl;
    // cout << ((max(((x + k - 1) / k) * k - l - x, 0LL) + l * 2 - 1) / (l * 2)) << endl;
    // cout << ((max(y - (y / k * k + l), 0LL) + l * 2 - 1) / (l * 2)) << endl;
    return 0;
}