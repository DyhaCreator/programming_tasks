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
        int kkk = 0;
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < m; y1++) {
                for (int x2 = x1 + 1; x2 < n; x2++) {
                    for (int y2 = y1 + 1; y2 < m; y2++) {
                        if (vec[x1][y1] == vec[x2][y2] && vec[x2][y1] == vec[x1][y2] && vec[x1][y1] == vec[x2][y1]) {
                            kkk++;
                            break;
                        }
                    }
                    if (kkk > 0) break;
                }
                if (kkk > 0) break;
            }
            if (kkk > 0) break;
        }
        if (kkk == 0) {
            for (auto &i : vec) {
                for (auto &j : i)
                    cout << j << " ";
                cout << endl;
            }
            cout << endl;
        }
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
    vec[x][y] = 3;
    f(x, y, vec);
}

int main() {
    cin >> n >> m >> c;
    vector<vector<int>> vec(n, vector<int>(m, 1));
    f(0, 0, vec);
    vec[0][0] = 2;
    f(0, 0, vec);
    vec[0][0] = 3;
    f(0, 0, vec);
    return 0;
}