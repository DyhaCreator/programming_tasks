#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < a.size(); i+=2) {
        a.push_back(a[i] + a[i + 1] - 1);
    }
    cout << a[a.size() - 1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}