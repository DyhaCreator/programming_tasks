#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> a = vector<vector<int >> (n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    clock_t tStart = clock();
    vector<vector< int >> b = vector<vector< int >> (n + 1, vector<int>(m));
    for (int y = 1; y <= n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y - 1][x] == 0) {
                b[y][x] = b[y - 1][x] + 1;
            } else {
                b[y][x] = 0;
            }
        }
    }
    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
/*

4 4
0 0 0 0
0 1 0 1
0 0 0 0
1 1 0 0

5 6
1 0 0 0 1 0
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0

*/