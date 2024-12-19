#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct star{
    int x, y, s;
    star() {}
    star(int x, int y, int s) {
        this->x = x;
        this->y = y;
        this->s = s;
    }
};

int main() {
    int n, q, c;
    cin >> n >> q >> c;
    vector<star> a(n);
    for (auto &x : a)
        cin >> x.x >> x.y >> x.s;
    vector<vector<vector<int>>> mp(c + 1, vector<vector<int>>(100, vector<int>(100)));
    for (int i = 0; i < c + 1; i++) {
        for (auto &x : a)
            mp[i][x.y - 1][x.x - 1] += (x.s + i) % (c + 1);
    }
    vector<vector<vector<int>>> pref(c + 1, vector<vector<int>>(101, vector<int>(101)));
    for (int i = 0; i < c + 1; i++) {
        for (int y = 0; y < 100; y++) {
            for (int x = 0; x < 100; x++) {
                pref[i][y + 1][x + 1] = pref[i][y + 1][x] + pref[i][y][x + 1] - pref[i][y][x] + mp[i][y][x];
            }
        }
    }

    /*for (auto &z : mp) {
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++)
                cout << z[y][x] << " ";
            cout << endl;
        }
        cout << endl;
    }*/

    for (int i = 0; i < q; i++) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        y1--;x1--;
        cout << pref[t % (c + 1)][y2][x2] - pref[t % (c + 1)][y2][x1] - pref[t % (c + 1)][y1][x2] +pref[t % (c + 1)][y1][x1] << endl;
    }
    return 0;
}