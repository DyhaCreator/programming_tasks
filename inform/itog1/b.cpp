#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x : a) for (auto &y : x) cin >> y;
    ll sum = 0;
    for (auto &x : a[0])
        sum += x;
    for (auto &x : a) {
        ll sum2 = 0;
        for (auto &y : x)
            sum2 += y;
        if (sum2 != sum) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int y = 0; y < n; y++) {
        ll sum2 = 0;
        for (int x = 0; x < n; x++)
            sum2 += a[x][y];
        if (sum2 != sum) {
            cout << "NO" << endl;
            return 0;
        }
    }
    ll sum2 = 0;
    ll sum3 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += a[i][i];
        sum3 += a[i][n - i - 1];
    }
    if (sum2 != sum || sum3 != sum) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}