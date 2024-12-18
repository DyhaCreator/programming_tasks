#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct point{
    int x, type, line;
    vector<int>lines = {};
    point *pare;
    point() {}
    point(int x, int type, int line) {
        this->x = x;
        this->type = type;
        this->line = line;
    }
};

bool comp(point &a, point &b) {
    if (a.x == b.x) {
        return a.type > b.type;
    }
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    vector<point>points = {};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        point p1 = point(a, +1, i + 1), p2 = point(b, -1, i + 1);
        p1.pare = &p2;
        p2.pare = &p1;
        points.push_back(p1);
        points.push_back(p2);
    }

    sort(points.begin(), points.end(), comp);

    vector<int>ins = vector<int>(n);
    for (int i = 0; i < points.size(); i++) {
        if (points[i].type == +1) {
            ins[points[i].line - 1] = 1;
            points[i].lines = ins;
        } else {
            ins[points[i].line - 1] = 0;
        }
    }
    return 0;
}