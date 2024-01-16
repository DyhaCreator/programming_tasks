#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct point{
    int x, type, h;
    point() {}
    point(int x, int type) {
        this->x = x;
        this->type = type;
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
    n *= 2;
    vector<point>points(n);
    for (int i = 0; i < n; i += 2) {
        cin >> points[i].x;
        cin >> points[i + 1].x;
        points[i].type = 1;
        points[i + 1].type = -1;
    }
    sort(points.begin(), points.end(), comp);
    vector<point>ans = {};
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h == 0) {
            ans.push_back(point(points[i].x, points[i].x));
        } else {
            ans[ans.size() - 1].type = points[i].x;
        }
        h += points[i].type;
    }
    cout << ans.size() << endl;
    for (auto &x : ans) {
        cout << x.x << " " << x.type << endl;
    }
    return 0;
}