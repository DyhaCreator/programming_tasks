#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct vec{
    int y, x;
    vec() {}
    vec(int y, int x) {
        this->y = y;
        this->x = x;
    }
    int len2() {
        return y * y + x * x;
    }
};

int sc(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}
int vc(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

bool f2(vec a, vec b) {
    return sc(a, b) == 0 && vc(a, b) > 0 && a.len2() >= b.len2();
}

bool f(vector<vec> a, vec b) {
    vec v0b = vec(b.x - a[0].x, b.y - a[0].y);
    vec v01 = vec(a[1].x - a[0].x, a[1].y - a[0].y);
    vec v1b = vec(b.x - a[1].x, b.y - a[1].y);
    vec v12 = vec(a[2].x - a[1].x, a[2].y - a[1].y);
    vec v2b = vec(b.x - a[2].x, b.y - a[2].y);
    vec v23 = vec(a[3].x - a[2].x, a[3].y - a[2].y);
    vec v3b = vec(b.x - a[3].x, b.y - a[3].y);
    vec v30 = vec(a[0].x - a[3].x, a[0].y - a[3].y);
    // cout << b.x << " " << b.y << endl;
    // cout << sc(v0b, v01) << " " << sc(v1b, v12) << " " << sc(v2b, v23) << " " << sc(v3b, v30) << endl;
    if ((sc(v0b, v01) > 0 == sc(v1b, v12) > 0 &&
        sc(v1b, v12) > 0 == sc(v2b, v23) > 0 && 
        sc(v2b, v23) > 0 == sc(v3b, v30) > 0) || 
        f2(v01, v0b) || f2(v12, v1b) || 
        f2(v23, v2b) || f2(v30, v3b)) {
        return 1;
    }
    return 0;
}

bool f3(vec a, vec b, vec c, vec d) {
    vec v1 = vec(c.y - a.y, c.x - a.x);
    vec v2 = vec(d.y - a.y, d.x - a.x);
    vec v3 = vec(b.y - a.y, b.x - a.x);
    // cout << a.x << " " << a.y << "  " << b.x << " " << b.y << "   " << c.x << " " << c.y << "  " << d.x << " " << d.y << endl;
    // cout << v1.x << " " << v1.y << "  " << v2.x << " " << v2.y << "  " << v3.x << " " << v3.y << endl;
    if (sc(v1, v3) > 0 == sc(v3, v2) > 0 || sc(v1, v3) == 0 || sc(v3, v2) == 0) {
        v1 = vec(b.x - c.x, b.y - c.y);
        v2 = vec(a.x - c.x, a.y - c.y);
        v3 = vec(d.x - c.x, d.y - c.y);
        if (sc(v1, v3) > 0 == sc(v3, v2) > 0 || sc(v1, v3) == 0 || sc(v3, v2) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    vector<vec> a(4);
    vector<vec> b(4);
    for (auto &x : a)
        cin >> x.x >> x.y;
    for (auto &x : b)
        cin >> x.x >> x.y;
    for (auto &x : b) {
        if (f(a, x)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (auto &x : a) {
        if (f(b, x)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (f3(a[i], a[(i + 1) % 4], b[j], b[(j + 1) % 4])) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}