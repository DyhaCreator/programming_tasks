#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    cout << fixed;
    cout.precision(2);
    cout << sqrt(sum) << endl;
    return 0;
}