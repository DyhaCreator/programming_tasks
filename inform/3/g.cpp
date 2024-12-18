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

struct vec{
    int x, y;
    vec() {}
    vec(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int2 a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    int g1 = (a.x - d.x) * (a.y - b.y) - (a.y - d.y) * (a.x - b.x);
    int g2 = (b.x - d.x) * (b.y - c.y) - (b.y - d.y) * (b.x - c.x);
    int g3 = (c.x - d.x) * (c.y - a.y) - (c.y - d.y) * (c.x - a.x);
    if ((g1 >= 0 && g2 >= 0 && g3 >= 0) || (g1 <= 0 && g2 <= 0 && g3 <= 0)) {
        cout << "In" << endl;
    } else {
        cout << "Out" << endl;
    }
    return 0;
}