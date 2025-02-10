#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool comp(vector<ll> &a, vector<ll> &b) {
    vector<ll> c = a;
    vector<ll> d = b;
    for (auto &x : b) c.push_back(x);
    for (auto &x : a) d.push_back(x);
    ll sum1 = 0;
    ll sum2 = 0;
    for (auto &x : c) {
        sum1 += x;
        sum2 += sum1;
    }
    ll sum3 = 0;
    ll sum4 = 0;
    for (auto &x : d) {
        sum3 += x;
        sum4 += sum3;
    }
    if (sum2 < sum4)
        return 1;
    return 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    sort(a.begin(), a.end(), comp);
    reverse(a.begin(), a.end());
    vector<ll> b = {};
    for (auto &x : a) {
        for (auto &y : x)
            b.push_back(y);
    }
    vector<ll> pref(b.size() + 1);
    for (int i = 0; i < b.size(); i++)
        pref[i + 1] = pref[i] + b[i];
    ll sum = 0;
    for (auto &x : pref)
        sum += x;
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}