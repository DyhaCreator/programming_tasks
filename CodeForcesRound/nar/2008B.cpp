#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int y = 1;
    while (y * y < n)
        y++;
    string str;
    cin >> str;
    if (y * y != n) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < y; j++) {
            if ((i == 0 || j == 0 || i == y - 1 || j == y - 1) && str[i * y + j] == '0') {
                cout << "NO" << endl;
                return;
            } else if (i != 0 && j != 0 && i != y - 1 && j != y - 1 && str[i * y + j] == '1') {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}