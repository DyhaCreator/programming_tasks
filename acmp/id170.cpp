#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll f(ll n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    cin >> n;
    int maxLen = 1;
    for (int len = 2; len <= sqrt(n) * 2; len++) {
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (f(m + len) - f(m) < n) {
                l = m + 1;
            } else {
                r = m;
            }
            // cout << m << " " << f(m + len) - f(m) << endl;
        }
        // cout << f(l + len) - f(l) << endl;
        if (f(l + len) - f(l) == n) {
            maxLen = len;
        }
    }
    cout << maxLen << endl;
    return 0;
}