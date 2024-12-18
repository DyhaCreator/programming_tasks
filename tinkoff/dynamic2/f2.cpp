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
    vector<vector<int >> a = vector<vector<int >> (w + 1, vector<int>(n + 1));
    vector<vector<vector<int >> >b = vector<vector<vector<int >> >(w + 1, vector<vector<int >> (n + 1, vector<int>()));
    for (int y = 1; y <= w; y++) {
        for (int x = 1; x <= n; x++) {
            if (y >= m[x - 1]) {
                if (a[y][x - 1] > a[y - m[x - 1]][x - 1] + c[x - 1]) {
                    a[y][x] = a[y][x - 1];
                    b[y][x] = b[y][x - 1];
                } else {
                    a[y][x] = a[y - m[x - 1]][x - 1] + c[x - 1];
                    b[y][x] = b[y - m[x - 1]][x - 1];
                    b[y][x].push_back(x);
                }
            } else {
                a[y][x] = a[y][x - 1];
                b[y][x] = b[y][x - 1];
            }
        }
    }
    cout << b[w][n].size() << endl;
    for (auto x : b[w][n])
        cout << x << endl;
    return 0;
}