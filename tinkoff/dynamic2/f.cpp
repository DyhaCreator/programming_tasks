#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int>m = vector<int>(n);
    for (auto &x : m)
        cin >> x;
    vector<int>c = vector<int>(n);
    for (auto &x : c)
        cin >> x;
    vector<vector<int>>a = vector<vector<int>>(w + 1, vector<int>(n + 1));
    vector<vector<int>>b = vector<vector<int>>(w + 1, vector<int>(n + 1));
    for (int y = 1; y <= w; y++) {
        for (int x = 1; x <= n; x++) {
            if (m[x - 1] <= y) {
                if (a[y - m[x - 1]][x - 1] + c[x - 1] > a[y][x - 1]) {
                    a[y][x] = a[y - m[x - 1]][x - 1] + c[x - 1];
                    b[y][x] = x;
                } else {
                    a[y][x] = a[y][x - 1];
                    b[y][x] = x;
                }
            } else {
                a[y][x] = a[y][x - 1];
                b[y][x] = 0;
            }
            //cout << b[y][x] << " ";
        }
        //cout << endl;
    }
    int y = w;
    int x = n;
    while (y > 0 && x > 0) {
        if (b[y][x] != 0) {
            cout << b[y][x] << endl;
            y -= m[b[y][x] - 1];
        }
        x--;
    }
    //cout << a[w][n] << endl;
    return 0;
}