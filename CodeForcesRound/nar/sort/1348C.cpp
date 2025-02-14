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
    sort(a.begin(), a.end());
    vector<string> b(k);
    for (int i = 0; i < k; i++)
        b[i].push_back(a[i]);
    int index = k;
    while (index < n && (a[index] == b[0].back() || index % k == 0)) {
        b[index % k].push_back(a[index]);
        index++;
    }
    for (auto &x : b)
        cout << x << endl;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}