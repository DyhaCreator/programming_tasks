#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define INF 10000000007
using namespace std;

struct int2{
    ll x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

vector<vector<int2>> g;

vector<int> d(int start) {
    return {};
}

int main() {
    int n;
    cin >> n;
    vector<int2> v(n);
    g = vector<vector<int2>>(n, vector<int2>());
    for (auto &x : v) {
        cin >> x.x >> x.y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                g[i].push_back(int2(j, (v[i].x - v[j].x) * (v[i].x - v[j].x) + 
                               (v[i].y - v[j].y) * (v[i].y - v[j].y)));
                // cout << g[i].back().x << " ";
            }
        }
        // cout << endl;
    }


    return 0;
}