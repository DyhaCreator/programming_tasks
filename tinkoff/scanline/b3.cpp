#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

struct point{
    ll x, type;
    point() {}
    point(int x, int type) {
        this->x = x;
        this->type = type;
    }
};

bool comp(const point &a, const point &b) {
    return (a.x < b.x || (a.x == b.x && a.type > b.type));
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<point>points = vector<point>();
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back(point(std::min(x, y), 1));
        points.push_back(point(std::max(x, y), -1));
    }
    vector<point>rp = vector<point>();
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        rp.push_back(point(x, 0));
        points.push_back(point(x, 0));
    }

    sort(points.begin(), points.end(), comp);

    map<ll, ll>mp;
    ll h = 0;
    for (int i = 0; i < points.size(); i++) {
        h += points[i].type;
        if (points[i].type == 0) {
            mp[points[i].x] = h;
        }
    }
    for (auto &x : rp) {
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