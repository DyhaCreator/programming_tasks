#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > n - 1 || (k == n - 1 && n == 4)) {
        cout << -1 << endl;
        return;
    }
    vector<int> used(n);
    if (k == n - 1) {
        used[n - 1] = 1;
        used[k - 1] = 1;
        used[n - 3] = 1;
        used[1] = 1;
        cout << n - 1 << " " << k - 1 << endl;
        cout << n - 3 << " " << 1 << endl;
    } else {
        used[n - 1] = 1;
        used[k] = 1;
        cout << n - 1 << " " << k << endl;
    }
    int c = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (used[i] == 0) {
            used[i] = 1;
            for (int j = n - c; j >= 0; j--) {
                if ((i & j) == 0 && used[j] == 0) {
                    cout << i << " " << j << endl;
                    used[i] = 1;
                    used[j] = 1;
                    break;
                }
            }
            c++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}