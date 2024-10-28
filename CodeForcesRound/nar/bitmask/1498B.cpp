#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<int> count(30);
    int y = 0;
    for (auto &x : a) {
        while ((1 << y) < x)
            y++;
        count[y]++;
    }
    vector<int> c(n + 1);
    for (int i = 29; i >= 0; i--) {
        int index = 0;
        for (int j = 0; j < count[i]; j++) {
            while (c[index] + (1 << i) > w)
                index++;
            if (c[index] + (1 << i) <= w)
                c[index] += (1 << i);
        }
    }
    int ans = 0;
    while (c[ans] != 0)
        ans++;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}