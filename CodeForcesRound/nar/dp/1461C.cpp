#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<pair<int, double>> qq(m);
    for (auto &x : qq)
        cin >> x.first >> x.second;
    sort(qq.begin(), qq.end());
    int index = n - 1;
    while (index >= 1 && a[index] == index + 1) index--;
    if (index == 0) {
        printf("%.6f\n", 1.0);
        return;
    }
    vector<pair<int, double>> q = {};
    for (auto &x : qq)
        if (x.first > index) q.push_back(x);
    double ans = 0;
    for (auto &x : q)
        ans += (1.0 - ans) * x.second;
    printf("%.6f\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}