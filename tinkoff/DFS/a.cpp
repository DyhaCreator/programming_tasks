#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> a(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cout << a[y][x] << " ";
        }
        cout << endl;
    }
    return 0;
}