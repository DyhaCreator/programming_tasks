#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll last(ll n) {
    while (n % 10 == 0) {
        n /= 10;
    }
    return n % 1000000;
}

int main() {
    ll n;
    cin >> n;
    ll num = 1;
    for (ll i = 1; i <= n; i++) {
        num *= i;
        // cout << i << " " << num << endl;
        num = last(num);
    }
    cout << num % 10 << endl;
    return 0;
}