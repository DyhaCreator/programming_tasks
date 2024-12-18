#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int q = n;
    int w = m;
    n = max(n, m);
    m = max(n, m);
    vector<vector<int>>a = vector<vector<int>>(n + 3, vector<int>(m + 3));
    for (int sum = 2; sum <= n + m; sum++) {
        for (int x = max(sum - n, 1); x <= sum - max(sum - n, 1); x++) {
            int y = sum - x;
            if (x + 1 == 2 && y + 1 == 2) {
                a[y + 1][x + 1] = 1;
            } else {
                a[y + 1][x + 1] = a[y + 1 - 2][x + 1 + 1] + a[y + 1 - 2][x + 1 - 1] + a[y + 1 - 1][x + 1 - 2] + a[y + 1 + 1][x + 1 - 2];
            }
        }
    } 
    for (int y = 0; y < n + 3; y++) {
        for (int x = 0; x < m + 3; x++) {
            cout << a[y][x] << " ";
        }
        cout << endl;
    }
    cout << a[q + 1][w + 1] << endl;
    return 0;
}