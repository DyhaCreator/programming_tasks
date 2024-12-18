#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

struct line{
    int start;
    int end;
    line() {}
    line(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct point{
    int x, type;
    point() {}
    point(int x, int type) {
        this->x = x;
        this->type = type;
    }
};

bool comp(const line &a, const line &b) {
    if (a.start == b.start) {
        return a.end < b.end;
    } else {
        return a.start < b.start;
    }
}

bool comp2(const point &a, const point &b) {
    if (a.x == b.x) {
        if (a.type == 0 && b.type != 0) {
            return false;
        } else if (b.type == 0 && a.type != 0) {
            return true;
        } else if (a.type == 0 && b.type == 0) {
            return false;
        }
    }
    return a.x < b.x;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<line>lines(n);
    for (auto &[a, b] : lines) {
        int x, y;
        cin >> x >> y;
        a = std::min(x, y);
        b = std::max(x, y);
        //cin >> a >> b;
    }
    sort(lines.begin(), lines.end(), comp);
    lines.push_back(line(1000000001, 1000000007));
    vector<point>points(m);
    for (auto &x : points) {
        cin >> x.x;
        x.type = 0;
    }
    vector<point>enterPoints = points;

    int indexStart = 0;
    int indexEnd = 0;

    while (indexEnd < n) {
        if (indexStart < n && lines[indexStart].start < lines[indexEnd].end) {
            points.push_back(point(lines[indexStart].start, 1));
            indexStart++;
        } else {
            points.push_back(point(lines[indexEnd].end, -1));
            indexEnd++;
        }
    }

    sort(points.begin(), points.end(), comp2);

    /*
    for (auto &x : points) {
        cout << x.x << " " << x.type << endl;
    }
    */

    int h = 0;
    map<int, int>mp;

    for (auto &x : points) {
        h += x.type;
        if (x.type == 0) {
            mp[x.x] = h;
        }
    }

    for (auto &x : enterPoints) {
        cout << mp[x.x] << " ";
    }

    cout << endl;
    return 0;
}
/*

5 1
1 4
6 10
3 7
2 5
3 8
3

3 2
0 5
-3 2
7 10
1 6

1 3
-10 10
-100 100 0


*/