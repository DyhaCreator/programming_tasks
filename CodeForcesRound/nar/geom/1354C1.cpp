#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    double pi = 3.141592653589793238462643383279502884L;
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += sin(pi / n * i);
    printf("%.6f\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}