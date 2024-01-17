#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct point{
    int x, type, index;
    point() {}
    point(int x, int type, int index) {
        this->x = x;
        this->type = type;
        this->index = index;
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
        /*points[i] = point(b, -1);
        points[i + 1] = point(a, +1, i - 1);*/
        points.push_back(point(b, -1, i));
        points.push_back(point(a, +1, i));
    }
    sort(points.begin(), points.end(), comp);
    /*for (auto &x : points)
        cout << x.x << " " << x.type << endl;*/
    int h = 0;
    int ans = 0;
    vector<int>aaa = vector<int>(n);
    for (int i = 0; i < int(points.size()); i++) {
        if (h < k && points[i].type == +1) {
            ans++;
            h++;
        } else if (points[i].type == -1 && aaa[points[i].index] == 0) {
            h--;
        } else if (points[i].type == +1) {
            aaa[points[i].index] = 1;
            // cout << points[i].a->x << endl;
            // points[i].a->type = 0;
        }
        cout << h << " ";
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}