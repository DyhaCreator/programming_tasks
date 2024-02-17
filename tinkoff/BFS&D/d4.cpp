#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

struct point{
    int x, y;
    point() {}
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int n;
vector<point> g;

vector<int> d(int s) {
    vector<int> dist(n, INF);
    dist[s] = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        int near = -1;
        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && (near == -1 || dist[near] > dist[v])) {
                near = v;
            }
            // cout << near << " ";
        }
        // cout << near << endl;
        visited[near] = 1;

        for (int v = 0; v < n; v++) {
            int l = ((g[near].x - g[v].x) * (g[near].x - g[v].x) + (g[near].y - g[v].y) * (g[near].y - g[v].y));
            if (v != near && dist[v] > dist[near] + l) {
                dist[v] = dist[near] + l;
            }
        }
        /*for (auto &x : dist)
            cout << x << " ";
        cout << endl;*/
    }

    return dist;
}

int main() {
    cin >> n;
    g = vector<point>(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[i] = point(x, y);
    }
    int s, f;
    cin >> s >> f;
    s--;
    f--;
    vector<int> dist = d(s);
    cout << dist[f] << endl;
    return 0;
}