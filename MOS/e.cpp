#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x = 0;
    int y = 0;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

vector<vector<int>>map;
int n, m;
int ans;

int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

bool in(int2 a, vector<int2>b) {
    for (auto x : b) {
        if (x.x == a.x && x.y == a.y) {
            return true;
        }
    }
    return false;
}

void rec(int x, int y, vector<int2>path) {
    /*for (auto x : path) {
        cout << x.x << " " << x.y << "  ";
    } 
    cout << endl;*/
    if (x == 0 && y == 0) {
        if (path.size() < ans || ans == -1) {
            ans = path.size() - 1;
        }
        return;
    }
    path.push_back(int2(-1, -1));
    for (int y2 = 0; y2 < n; y2++) {
        for (int x2 = 0; x2 < m; x2++) {
            //cout << x2 << " " << y2 << " " << map[y2][x2] << " " << x << " " << y << " " << map[y][x] << " " << in(int2(x2, y2), path) << " " << nod(map[y2][x2], 4) << endl;
            if ((!in(int2(x2, y2), path)) && (nod(map[y2][x2], map[y][x]) > 1)) {
                path[path.size() - 1] = int2(x2, y2);

                rec(x2, y2, path);

                path[path.size() - 1] = int2(-1, -1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    ans = -1;
    map = vector<vector<int>>(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    rec(m - 1, n - 1, {int2(n - 1, m - 1)});
    cout << ans << endl;
}

/*

3 3
6 9 5
8 6 21
77 14 11

*/