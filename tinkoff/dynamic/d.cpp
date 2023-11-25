#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define sz .size()
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> map = vector<vector<int >> (n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<int >> a = vector<vector<int >> (n + 1, vector<int>(m + 1));
    vector<vector<vector<char >> >b = vector<vector<vector<char >> >(n + 1, vector<vector<char >> (m + 1, vector<char>()));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (a[y - 1][x] > a[y][x - 1]) {
                a[y][x] = a[y - 1][x] + map[y - 1][x - 1];
                b[y][x] = b[y - 1][x];
                b[y][x].push_back('D');
            } else {
                a[y][x] = a[y][x - 1] + map[y - 1][x - 1];
                b[y][x] = b[y][x - 1];
                b[y][x].push_back('R');
            }
        }
    }
    cout << a[n][m] << endl;
    b[n][m].erase(b[n][m].begin());
    for (auto x : b[n][m])
        cout << x << " ";
    cout << endl;
    /*for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= m; x++) {
            cout << a[y][x] << " ";
            for (auto x : b[y][x])
                cout << x << " ";
            cout << "   ";
        }
        cout << endl;
    }*/
    return 0;
}