#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    int xx = 0;
    for (int i = 0; i < n; i++)
        xx = xx ^ a[i][0];
    if (xx != 0) {
        cout << "TAK" << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if ((xx ^ a[i][0] ^ a[i][j]) != 0) {
                    cout << "TAK" << endl;
                    for (int k = 0; k < n; k++) {
                        if (k == i) {
                            cout << j + 1 << " ";
                        } else {
                            cout << 1 << " ";
                        }
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
        cout << "NIE" << endl;
    }
    return 0;
}