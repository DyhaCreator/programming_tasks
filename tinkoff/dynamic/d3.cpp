#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>map = vector<vector<int>>(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<vector<int>>a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    vector<vector<char>>b = vector<vector<char>>(n + 1, vector<char>(m + 1));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (x == 1 && y == 1) {
                a[1][1] = map[0][0];
            } else {
                if (a[y - 1][x] >= a[y][x - 1]) {
                    a[y][x] = a[y - 1][x] + map[y - 1][x - 1];
                    b[y][x] = 'D';
                } else {
                    a[y][x] = a[y][x - 1] + map[y - 1][x - 1];
                    b[y][x] = 'R';
                }
            }
            //cout << a[y][x] << " " << b[y][x] << " ";
        }
        //cout << endl;
    }
    cout << a[n][m] << endl;
    vector<char>ans = vector<char>();
    int x = n;
    int y = m;
    while (x > 1 || y > 1) {
        if (b[y][x] == 'D') {
            y--;
            ans.push_back('D');
        } else if (b[y][x] == 'R') {
            x--;
            ans.push_back('R');
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}