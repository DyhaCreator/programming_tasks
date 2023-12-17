#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
    int k, m, t, x;
    cin >> k >> m >> t >> x;
    if (t >= k * 7) {
        cout << -1 << endl;
        return 0;
    }
    k = k * 7;
    int day = 0;
    while (x < m) {
        x += k;
        if (x >= m) {
            x -= k;
            break;
        }
        x -= t;
        day += 7;
    }
    k = k / 7;
    day += ceil((float)(m - x) / (float)k);
    cout << day << endl;
    return 0;
}