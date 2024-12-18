#include <iostream>
#include <vector>
#define ll long long
#define szs .size()
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll >> map = vector<vector<ll >> (n, vector<ll>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<ll >> a = vector<vector<ll >> (n + 1, vector<ll>(m + 1));
    vector<vector<vector<char >> > way = vector<vector<vector<char >> >(n + 1, vector<vector<char >> (m + 1, vector<char>()));
    a[1][1] = map[0][0];
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (y == 1 && x == 1) {
                
            } else {
                if (a[y - 1][x] > a[y][x - 1]) {
                    a[y][x] = a[y - 1][x] + map[y - 1][x - 1];
                    way[y][x] = way[y - 1][x];
                    way[y][x].push_back('D');
                } else {
                    a[y][x] = a[y][x - 1] + map[y - 1][x - 1];
                    way[y][x] = way[y][x - 1];
                    way[y][x].push_back('R');
                }
            }
        }
    }
    cout << a[n][m] << endl;
    for (int i = 0; i < way[n][m]szs; i++) {
        cout << way[n][m][i] << " ";
    }
    cout << endl;
    return 0;
}