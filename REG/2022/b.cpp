#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

struct int2{
    int x;
    int y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

struct int4{
    int a, b, c, d;
    int4() {}
    int4(int a, int b, int c, int d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
};

struct trng{
    int2 a;
    int2 b;
    int2 c;
    float lenA = 0;
    float lenB = 0;
    float lenC = 0;
    trng() {}
    trng(int2 a, int2 b, int2 c, float lenA, float lenB, float lenC) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->lenA = lenA;
        this->lenB = lenB;
        this->lenC = lenC;
    }
};

bool f(trng &a, trng &b, trng &c, trng &d) {
    if (a.lenA == b.lenA || a.lenA == b.lenB || a.lenA == b.lenC) {
        if (a.lenB == c.lenA || a.lenB == c.lenB || a.lenB == c.lenC) {
            if (a.lenC == d.lenA || a.lenC == d.lenB || a.lenC == d.lenC) {
                return true;
            }
        } else if (a.lenC == c.lenA || a.lenC == c.lenB || a.lenC == c.lenC) {
            if (a.lenB == d.lenA || a.lenB == d.lenB || a.lenB == d.lenC) {
                return true;
            }
        }
    } else if (a.lenB == b.lenA || a.lenB == b.lenB || a.lenB == b.lenC) {
        if (a.lenA == c.lenA || a.lenA == c.lenB || a.lenA == c.lenC) {
            if (a.lenC == d.lenA || a.lenC == d.lenB || a.lenC == d.lenC) {
                return true;
            }
        } else if (a.lenC == c.lenA || a.lenC == c.lenB || a.lenC == c.lenC) {
            if (a.lenA == d.lenA || a.lenA == d.lenB || a.lenA == d.lenC) {
                return true;
            }
        }
    } else if (a.lenC == b.lenA || a.lenC == b.lenB || a.lenC == b.lenC) {
        if (a.lenA == c.lenA || a.lenA == c.lenB || a.lenA == c.lenC) {
            if (a.lenB == d.lenA || a.lenB == d.lenB || a.lenB == d.lenC) {
                return true;
            }
        } else if (a.lenB == c.lenA || a.lenB == c.lenB || a.lenB == c.lenC) {
            if (a.lenA == d.lenA || a.lenA == d.lenB || a.lenA == d.lenC) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<trng>v(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int2 a = int2(x, y);
        cin >> x >> y;
        int2 b = int2(x, y);
        cin >> x >> y;
        int2 c = int2(x, y);
        float lenA = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        float lenB = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
        float lenC = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
        v[i] = trng(a, b, c, lenA, lenB, lenC);
    }
    vector<int4>p = {};
    for (int a = 0; a < n - 3; a++) {
        for (int b = a + 1; b < n - 2; b++) {
            for (int c = b + 1; c < n - 1; c++) {
                for (int d = c + 1; d < n; d++) {
                    if (f(v[a], v[b], v[c], v[d])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                        //cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
                    } else if (f(v[a], v[b], v[d], v[c])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[a], v[c], v[b], v[d])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[a], v[c], v[d], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[a], v[d], v[c], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[a], v[d], v[b], v[c])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[b], v[a], v[c], v[d])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[b], v[a], v[d], v[c])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[b], v[d], v[a], v[c])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[b], v[d], v[c], v[a])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[b], v[c], v[a], v[d])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[b], v[c], v[d], v[a])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[c], v[a], v[b], v[d])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[c], v[a], v[d], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[c], v[b], v[a], v[d])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[c], v[b], v[d], v[a])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[c], v[d], v[a], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[c], v[d], v[b], v[a])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[d], v[a], v[c], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[d], v[a], v[b], v[c])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[d], v[b], v[a], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[d], v[b], v[b], v[a])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[d], v[c], v[a], v[b])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    } else if (f(v[d], v[c], v[b], v[a])) {
                        p.push_back(int4(a + 1, b + 1, c + 1, d + 1));
                    }
                }
            }
        }
    }
    cout << p.size() << endl;
    for (auto &x : p) {
        cout << x.a << " " << x.b << " " << x.c << " " << x.d << endl;
    }
    return 0;
}


int main() {
    return 0;
    int n;
    xanax >> n;
    vector<int>a(n);
    for (auto &x : a)
        cin >> x;
    int l = 0;
    int r = n;
    while (l < )
}