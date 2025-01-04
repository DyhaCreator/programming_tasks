#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != a[i][5 - j]) {
                a[i][j] = 'X';
                a[i][5 - j] = 'X';
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == '.' && count < m) {
                a[i][j] = 'X';
                a[i][5 - j] = 'X';
                count += 2;
            }
        }
    }
    if (count == m) {
        for (auto &x : a)
            cout << x << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}