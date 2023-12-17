#include <iostream>
#define ll long long
using namespace std;

int f(ll n) {
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n & i) continue;
        cnt += 2;
    }
    return cnt;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        ll n;
        cin >> n;
        cout << f(n) << endl;
    }
    cout << endl;
    return 0;
}