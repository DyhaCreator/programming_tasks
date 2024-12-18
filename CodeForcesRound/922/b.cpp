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

bool comp(const int2 &a, const int2 &b) {
    if (abs(a.x - b.x) > abs(a.y - b.y)) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int2>ab(n);
        for (auto &x : ab)
            cin >> x.x;
        for (auto &x : ab)
            cin >> x.y;
        sort(ab.begin(), ab.end(), comp);
        for (auto &x : ab)
            cout << x.x << " ";
        cout << endl;
        for (auto &x : ab)
            cout << x.y << " ";
        cout << endl;
    }
    return 0;
}