#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
ll n, k;

ll f(vector<int> &a, ll m) {
    ll sum = 0;
    for (int i = n / 2; i < n; i++)
        sum += max(0LL, m - a[i]);
    return sum;
}

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll l = 0;
    ll r = 3000000000;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (f(a, m) > k) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}