#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    vector<string> s(9);
    for (auto &x : s)
        cin >> x;
    vector<vector<int>> a(9, vector<int>(9));
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            a[y][x] = s[y][x] - '0';
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            a[y * 3 + x][x * 3 + y] = a[y * 3 + x][x * 3 + y] % 9 + 1;
        }
    }
    for (auto &x : a) {
        for (auto &y : x)
            cout << y;
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}