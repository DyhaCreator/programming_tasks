#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#define ll long long
using namespace std;

int main() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll min_k = 0;
    ll min_r = 1e18 + 10;
    for (int i = 0; i <= a + b; i++) {
        ll suma;
        if (i <= a) {
            suma = x * i;
        } else {
            suma = x * a + y * (i - a);
        }
        ll sumb;
        if (a + b - i <= b) {
            sumb = y * (a + b - i);
        } else {
            sumb = y * b + x * ((a + b - i) - b);
        }
        if (abs(suma - sumb) < min_r) {
            min_r = abs(suma - sumb);
            min_k = i;
        }
        //cout << suma << " " << sumb << endl;
    }
    cout << min_k << "\n";
    return 0;
}