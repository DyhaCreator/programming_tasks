#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<int> cnt(26);
    for (auto &x : a)
        cnt[x - 'a']++;
    int p = 0;
    for (auto &x : cnt)
        p += x / 2;
    int d = 0;
    for (auto &x : cnt)
        d += x % 2;
    cout << p / k * 2 + ((p - p / k * k) * 2 + d >= k) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}