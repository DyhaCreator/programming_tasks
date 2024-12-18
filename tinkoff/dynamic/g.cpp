#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll >> a = vector<vector<ll >> (n + 2, vector<ll>(m + 2));
    a[1][1] = 1;
    for (int y = 2; y <= n; y++) {
        for (int x = 2; x <= m; x++) {
            a[y][x] = a[y - 2][x - 1] + a[y - 1][x - 2];
        }
    }
    cout << a[n][m] << endl;
    return 0;
}