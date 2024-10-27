#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n;

int gen(vector<int> &a, vector<int> &used, int count, int x) {
    if (count == n) {
        return 1;
    }
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (used[j] == 0 && (a[i] ^ a[j]) == x) {
                    used[j] = 1;
                    if (gen(a, used, count + 2, x))
                        found = 1;
                    used[j] = 0;
                }
            }
            used[i] = 0;
            break;
        }
    }
    return found;
}


void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    vector<int> used(n);
    int ans = INF;
    for (int i = 0; i < 1024; i++) {
        if (gen(a, used, 0, i))
            ans = min(i, ans);
    }
    if (ans == INF) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}