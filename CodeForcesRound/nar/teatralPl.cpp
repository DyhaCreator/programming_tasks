#include <iostream>
#define ll long long
using namespace std;

ll cp(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ll n, m, a;
    cin >> n >> m >> a;
    cout << cp(n, a) * cp(m, a) << endl;
    return 0;
}