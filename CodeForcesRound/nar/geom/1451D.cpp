#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    double d, k;
    cin >> d >> k;
    ll a = (d / k) / sqrt(2);
    if ((a + 1) * (a + 1) + a * a <= d * d) cout << "Ashish" << endl;
    else cout << "Utkarsh" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}