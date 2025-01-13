#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    map<pair<int, int>, int> mp;
    map<int, int> mpY;
    map<int, int> mpX;
    ll ans = 0;
    for (auto &x : a) {
        ans += mpY[x.F];
        ans += mpX[x.S];
        ans -= mp[x];
        mp[x]++;
        mpY[x.F]++;
        mpX[x.S]++;
    }
    cout << ans << endl;
    return 0;
}