#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n * 2; j++) {
            if ((i / 2) % 2 == (j / 2) % 2) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}