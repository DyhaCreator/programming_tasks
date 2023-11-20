#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

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
    vec(int x1, int y1, int x2, int y2) {
        this->x = x1 - x2;
        this->y = y1 - y2;
    }
};

float cp(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

struct polygon{
    int num, n;
    vector<int2>v = vector<int2>();
    polygon() {}
    polygon(int num, int n, vector<int2>v) {
        this->num = num;
        this->n = n;
        this->v = v;
    }
    float s() {
        float s = 0;
        vec a = vec(v[0].x, v[0].y, v[1].x, v[1].y);
        for (int i = 2; i < n; i++) {
            vec b = vec(v[0].x, v[0].y, v[i].x, v[i].y);
            s += (float)cp(a, b) / 2.0;
            a = b;
        }
        return abs(s);
    }
};

float S(vec a, vec b) {
    return (float)cp(a, b) / 2.0;
}

bool comp(polygon a, polygon b) {
    return a.s() > b.s();
}

int main() {
    int n;
    cin >> n;
    vector<polygon>v = vector<polygon>();
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vector<int2>p = vector<int2>();
        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            int2 vertex = int2(x, y);
            p.push_back(vertex);
        }
        polygon b(i, a, p);
        v.push_back(b);
    }
    vector<polygon>vp = v;
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++) {
        vp[v[i].num].num = i;
    }
    for (auto x : vp)
        cout << x.num << " ";
    cout << endl;
    return 0;
}
/*

3
3 -2 1 8 9 12 1
3 7 5 6 3 7 4
4 4 3 7 7 9 3 1 2

*/