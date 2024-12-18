#include <iostream>
#define ll long long
using namespace std;

unsigned ll n, a, b, w, h;

unsigned ll F(ll m) {
    return max((w / (a + m * 2)) * (h / (b + m * 2)), (w / (b + m * 2)) * (h / (a + m * 2)));
}

int main(){
    int ans, ans2;
    cin >> n >> a >> b >> w >> h;
    unsigned ll l = 0;
    unsigned ll r = w;
    for (unsigned ll m = 0; m <= r; m++) {
        if (F(m) < n) {
            ans = m;
            break;
        }
    }
    cout << ans << endl;
    while (l < r - 1) {
        unsigned ll m = (l + r) / 2;
        if (F(m) > n) {
            l = m;
        } else {
            r = m;
        }
        //cout << m << " " << (w / (a + m * 2)) * (h / (b + m * 2)) << " " << (w / (b + m * 2)) * (h / (a + m * 2)) << endl;
    }
    cout << l << endl;
    return 0;
}