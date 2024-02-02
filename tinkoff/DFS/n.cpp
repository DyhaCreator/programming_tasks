#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

int main() {
    int n, m;
    cin >> n >> m;

    g = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < m; i++) {
        int a, b, z;
        cin >> a >> b >> z;
        g[a - 1][b - 1] = z;
        g[b - 1][a - 1] = z;
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << g[y][x] << " ";
        }
        cout << endl;
    }

    
    return 0;
}