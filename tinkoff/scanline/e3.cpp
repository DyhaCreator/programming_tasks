#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct point{
    int x, type;
    point() {}
    point(int x, int type) {
        this->x = x;
        this->type = type;
    }
};

bool comp(point &a, point &b) {
    if (a.x == b.x) {
        return a.type < b.type;
    }
    return a.x < b.x;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<point> points = {};
    for (int i = 0; i < n; i++) {
        int s, f;
        cin >> s >> f;
        points.push_back(point(s, +1));
        points.push_back(point(f, -1));
    }

    sort(points.begin(), points.end(), comp);
    /*for (auto &x : points)
        cout << x.x << " " << x.type << endl;
    cout << endl;*/
    int ans = 0;
    int h = 0;
    for (int i = 0; i < points.size(); i++) {
        h += points[i].type;
        if (h <= k && points[i].type == +1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}