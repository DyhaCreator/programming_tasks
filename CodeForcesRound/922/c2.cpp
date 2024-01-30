#include <iostream>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b, r;
        cin >> a >> b >> r;
        ll ans = abs(a - b);
        ll cash = 1;
        ll mycash = 0;
        for (int i = 0; i < 63; i++) {
            if ((cash | mycash) <= r) {
                //if (abs((a ^ (cash | mycash))))
                if (abs((a ^ (cash | mycash)) - (b ^ (cash | mycash))) < ans) {
                    mycash = mycash | cash;
                    ans = abs((a ^ (cash | mycash)) - (b ^ (cash | mycash)));
                }
                cout << mycash << endl;
            }
            cash = cash << 1;
        }
        cout << mycash << " " << ans << endl;
        cout << endl;
    }
    return 0;
}