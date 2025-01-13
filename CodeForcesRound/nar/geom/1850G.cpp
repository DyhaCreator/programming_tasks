#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    map<int, int> mpY;
    map<int, int> mpX;
    map<int, int> mpM1;
    map<int, int> mpP1;
    ll ans = 0;
    for (auto &x : a) {
        ans += mpY[x.F];
        ans += mpX[x.S];
        ans += mpM1[x.F - x.S];
        ans += mpP1[x.F + x.S];
        mpY[x.F]++;
        mpX[x.S]++;
        mpM1[x.F - x.S]++;
        mpP1[x.F + x.S]++;
    }
    cout << ans * 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}