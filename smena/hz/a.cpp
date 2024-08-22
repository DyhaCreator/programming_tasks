#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int n, m, c;

void f(int x, int y, vector<vector<int>> &vec) {
    // cout << x << " " << y << endl;
    if (x >= n - 1 && y >= m - 1) {
        /*for (auto &i : vec) {
            for (auto &j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;*/
        
        return;
    }
    x++;
    if (x == n) {
        x = 0;
        y++;
    }
    vec[x][y] = 1;
    f(x, y, vec);
    vec[x][y] = 2;
    f(x, y, vec);
}

int main() {
    cin >> n >> m >> c;
    vector<vector<int>> vec(n, vector<int>(m, 1));
    f(0, 0, vec);
    vec[0][0] = 2;
    f(0, 0, vec);
    return 0;
}