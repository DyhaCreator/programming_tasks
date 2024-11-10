#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int vec(int2 a, int2 b) {
    return a.x * b.y - a.y * b.x;
}

int sc(int2 a, int2 b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    int2 a, b;
    int2 c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    int2 v1 = int2(b.x - a.x, b.y - a.y);
    int2 v2 = int2(c.x - a.x, c.y - a.y);
    int2 v3 = int2(d.x - a.x, d.y - a.y);
    // cout << vec(v1, v2) << " " << vec(v1, v3) << endl;
    int found1 = 0;
    if ((vec(v1, v2) > 0) != (vec(v1, v3) > 0) || vec(v1, v2) == 0 || vec(v1, v3) == 0) found1 = 1;
    v1 = int2(d.x - c.x, d.y - c.y);
    v2 = int2(a.x - c.x, a.y - c.y);
    v3 = int2(b.x - c.x, b.y - c.y);
    // cout << vec(v1, v2) << " " << vec(v1, v3) << endl;
    int found2 = 0;
    if ((vec(v1, v2) > 0) != (vec(v1, v3) > 0) || vec(v1, v2) == 0 || vec(v1, v3) == 0) found2 = 1;
    if (found1 && found2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}