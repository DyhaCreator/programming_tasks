#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m;

bool rec(int y, int x, vector<string> &map, char c, int step) {
    //cout << x << " " << y << endl;
    if (step == 3) {
        return false;
    }
    if (c == 'W' && y == 0) {
        return true;
    }
    if (x > 0 && map[y - 1][x - 1] == '.') {
        //cout << 1 << endl;
        if (rec(y - 1, x - 1, map, c, step + 1)) {
            return true;
        }
    } else if (x > 1 && y > 1 && map[y - 1][x - 1] == 'B' && map[y - 2][x - 2] == '.') {
        if (rec(y - 2, x - 2, map, c, step)) {
            return true;
        }
    }
    if (x < m && map[y - 1][x + 1] == '.') {
        //cout << 2 << endl;
        if (rec(y - 1, x + 1, map, c, step + 1)) {
            return true;
        }
        
    } else if (x < m - 1 && y > 1 && map[y - 1][x + 1] == 'B' && map[y - 2][x + 2] == '.') {
        if (rec(y - 2, x + 2, map, c, step)) {
            return true;
        }
    }
    return false;
}

bool recb(int y, int x, vector<string> &map, char c, int step) {
    //cout << x << " " << y << endl;
    if (step == 3) {
        return false;
    }
    if (c == 'W' && y == 0) {
        return true;
    }
    if (x > 0 && map[y - 1][x - 1] == '.') {
        //cout << 1 << endl;
        if (rec(y - 1, x - 1, map, c, step + 1)) {
            return true;
        }
    } else if (x > 1 && y > 1 && map[y - 1][x - 1] == 'W' && map[y - 2][x - 2] == '.') {
        if (rec(y - 2, x - 2, map, c, step)) {
            return true;
        }
    }
    if (x < m && map[y - 1][x + 1] == '.') {
        //cout << 2 << endl;
        if (rec(y - 1, x + 1, map, c, step + 1)) {
            return true;
        }
        
    } else if (x < m - 1 && y > 1 && map[y - 1][x + 1] == 'W' && map[y - 2][x + 2] == '.') {
        if (rec(y - 2, x + 2, map, c, step)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char c;
        cin >> n >> m >> c;
        vector<string> map(n);
        for (auto &x : map)
            cin >> x;
        // rec(4, 1, map, 'W', 1);
        bool b = false;
        if (c == 'w') {
            for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (b == true) {
                    break;
                }
                if (map[y][x] == 'W') {
                    if (rec(y, x, map, 'W', 1)) {
                        cout << y + 1 << " " << x + 1 << endl;
                        b = true;
                    }
                }
            }
        }
        if (b == false) {
            cout << "-1 -1" << endl;
        }
        } else {
            for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (b == true) {
                    break;
                }
                if (map[y][x] == 'B') {
                    if (recb(y, x, map, 'B', 1)) {
                        cout << y + 1 << " " << x + 1 << endl;
                        b = true;
                    }
                }
            }
        }
        if (b == false) {
            cout << "-1 -1" << endl;
        }
        }
    }
    return 0;
}