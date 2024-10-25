#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    // cout << a << endl;
    int count = 0;
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            count++;
        }
    }
    // cout << count << endl;
    vector<int> ans(n + 1, 0);
    if (n % 2 == 0) {
        for (int i = count; i < n + 1 - count; i++) {
            if ((i - count) % 2 == 0) {
                ans[i] = 1;
            }
        }
    } else {
        for (int i = count; i < n + 1 - count; i++) {
            ans[i] = 1;
        }
    }
    for (auto &x : ans)
        cout << x;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}