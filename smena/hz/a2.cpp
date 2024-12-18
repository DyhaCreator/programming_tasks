#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> a(n, vector<int>(m));
    int kkk = 1;
    int it = 0;
    srand(1);
    while (kkk > 0) {
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < m; y1++) {
                for (int x2 = x1 + 1; x2 < n; x2++) {
                    for (int y2 = y1 + 1; y2 < m; y2++) {
                        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                        if (a[x1][y1] == a[x2][y2] && a[x2][y1] == a[x1][y2] && a[x1][y1] == a[x2][y1]) {
                            int r = rand() % 4;
                            if (r == 0) {
                                a[x1][y1] = rand() % c;
                            } else if (r == 1) {
                                a[x2][y1] = rand() % c;
                            } else if (r == 2) {
                                a[x2][y2] = rand() % c;
                            } else if (r == 3) {
                                a[x1][y2] = rand() % c;
                            }
                            
                        }
                    }
                }
            }
        }
        kkk = 0;
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < m; y1++) {
                for (int x2 = x1 + 1; x2 < n; x2++) {
                    for (int y2 = y1 + 1; y2 < m; y2++) {
                        if (a[x1][y1] == a[x2][y2] && a[x2][y1] == a[x1][y2] && a[x1][y1] == a[x2][y1]) {
                            kkk++;
                        }
                    }
                }
            }
        }
        /*for (auto &x : a) {
            for (auto &y : x)
                cout << y + 1 << " ";
            cout << endl;
        }
        cout << kkk << endl;
        cout << endl;*/
    }
    if (c == 3 && (n < 4 || m < 4)) {
        a[0][0] = 2;
    }
    for (auto &x : a) {
        for (auto &y : x)
            cout << y + 1 << " ";
        cout << endl;
    }
    kkk = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1 + 1; x2 < n; x2++) {
                for (int y2 = y1 + 1; y2 < m; y2++) {
                    if (a[x1][y1] == a[x2][y2] && a[x2][y1] == a[x1][y2] && a[x1][y1] == a[x2][y1]) {
                        kkk++;
                    }
                }
            }
        }
    }
    // cout << kkk << endl;
    return 0;
}

// a[x1][y1] a[x1][y2] a[x2][y2] a[x2][y1]