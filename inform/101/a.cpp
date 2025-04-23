#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    cout << a + (b - a) * (n - 1) << endl;
    return 0;
}