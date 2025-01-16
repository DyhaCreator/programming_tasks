#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct vec{
    ll x, y;
    vec() {}
    vec(ll y, ll x) {
        this->y = y;
        this->x = x;
    }
    void print() {
        cout << x << " " << y << " ";
    }
};

struct box{
    vec a, b;
    box() {}
    box(vec a, vec b) {
        this->a = a;
        this->b = b;
    }
    ll s() {
        return (b.x - a.x) * (b.y - a.y);
    }
    void print() {
        a.print();
        b.print();
        cout << endl;
    }
};

box f(box a, box b) {
    if (a.b.y < b.a.y || a.b.x < b.a.x || a.a.y > b.b.y || a.a.x > b.b.x)
        return box(vec(-1, -1), vec(-1, -1));
    return box(vec(max(a.a.x, b.a.x), max(a.a.y, b.a.y)),
               vec(min(a.b.x, b.b.x), min(a.b.y, b.b.y)));
}

int main() {
    box a, b, c;
    cin >> a.a.y >> a.a.x >> a.b.y >> a.b.x;
    cin >> b.a.y >> b.a.x >> b.b.y >> b.b.x;
    cin >> c.a.y >> c.a.x >> c.b.y >> c.b.x;
    if (a.s() - f(a, b).s() - f(a, c).s() + f(f(a, b), f(a, c)).s() > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}