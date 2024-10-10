#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] + i);
    }
    cout << ans << endl;
    return 0;
}