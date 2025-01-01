#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 0 && a[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    cout << n + 1 << " " << j + 1 << " ";
                } else {
                    cout << j + 1 << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    if (a[0] == 1) {
        cout << n + 1 << " ";
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
        cout << endl;
    } else {
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
        cout << n + 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}