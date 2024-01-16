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
    int all = 0;
    vector<point>points = {};
    for (int i = 0; i < n; i++) {
        int h, m, s;
        cin >> h >> m >> s;
        int time1 = h * 3600 + m * 60 + s;
        cin >> h >> m >> s;
        int time2 = h * 3600 + m * 60 + s;
        if (time1 == time2) {
            //all++;
            points.push_back(point(0, +1));
            points.push_back(point(3600 * 24, -1));
            continue;
        }
        if (time1 > time2) {
            points.push_back(point(0, +1));
            points.push_back(point(time2, -1));
            points.push_back(point(time1, +1));
            points.push_back(point(24 * 3600, -1));
            continue;
        }
        points.push_back(point(time1, +1));
        points.push_back(point(time2, -1));
    }
    sort(points.begin(), points.end(), comp);
    int h = 0;
    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
        //cout << points[i].x << " " << h << endl;
        if (h == n && points[i].type == -1) {
            ans += points[i].x - points[i - 1].x;
        }
        h += points[i].type;
    }
    cout << ans << endl;
    return 0;
}