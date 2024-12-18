#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int index = 0;
    while (a[index] + a[index + 1] <= a[n - 1]) index++;
    reverse(a.begin(), a.end());
    int index2 = 0;
    while (a[index2] >= a[n - 1] + a[n - 2]) index2++;
    cout << min(index2, index) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}