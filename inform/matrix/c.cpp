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
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    vector<vector<int>> b(n, vector<int>(n));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            for (int z = 0; z < n; z++) {
                b[y][x] += a[y][z] * a[z][x];
            }
        }
    }
    for (auto &x : b) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}