#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>p1 = vector<int>(n);
    for (auto &x : p1)
        cin >> x;
    int m;
    cin >> m;
    vector<int>p2 = vector<int>(m);
    for (auto &x : p2)
        cin >> x;
    vector<vector<int>>a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (p1[y - 1] == p2[x - 1]) {
                a[y][x] = a[y - 1][x - 1] + 1;
            } else {
                a[y][x] = max(a[y - 1][x], a[y][x - 1]);
            }
        }
    }
    cout << a[n][m] << endl;
    return 0;
}