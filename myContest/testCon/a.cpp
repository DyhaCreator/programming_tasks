#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n, a;
    cin >> n >> a;
    ll ans = 0;
    ll x;
    while (cin >> x) {
        if (x >= a) {
            ans++;
            if (ans >= 4) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}