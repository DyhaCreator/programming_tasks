#include <iostream>
#include <vector>
#define ll long long
#define ull long long
using namespace std;

ull f(ull a, ull b, ull r) {
    ull ans = 1e18;
    ull cash = 1;
    for (int i = 0; i < 64; i++) {
        if (cash <= r) {
            ull fans = abs((a ^ cash) - (b ^ cash));
            //cout << cash << " " << fans << endl;
            if (fans < ans) {
                ans = fans;
            }
            cash = cash << 1;
        }
    }
    if (ans > abs(a - b)) {
        ans = abs(a - b);
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ull a, b, r;
        cin >> a >> b >> r;
        cout << f(a, b, r) << endl;
    }
    return 0;
}