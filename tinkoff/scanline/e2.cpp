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

bool comp(const point &a, const point &b) {
    if (a.x == b.x) {
        return a.type < b.type;
    }
    return a.x < b.x;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<point>points = vector<point>();
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back(point(a, +1));
        points.push_back(point(b, -1));
    }
    sort(points.begin(), points.end(), comp);
    int h = 0;
    int ans = 0;
    for (int i = 0; i < int(points.size()); i++) {
        h += points[i].type;
        if (h <= k && points[i].type == +1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}