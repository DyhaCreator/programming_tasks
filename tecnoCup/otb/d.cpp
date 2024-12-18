#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct int2{
    int x, y;
    int2(int x, int y) {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<vector<int>> mp(m, vector<int>(n));
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            mp[y][x] = 1;
        } else if (t == 1) {
            mp[y][x] = 0;
        } else if (t == 2) {
            queue<int2> q;
            q.push({x, y});
        }
    }
    return 0;
}