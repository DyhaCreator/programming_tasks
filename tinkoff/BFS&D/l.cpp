#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define ll long long
#define INF 1000000007
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator<(const int2 &b) {
        if (this->x == b.x) {
            return this->y < b.y;
        }
        return this->x < b.x;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int2 start, end;
    cin >> start.y >> start.x >> end.y >> end.x;
    vector<string> map(n);
    for (auto &x : map)
        cin >> x;
    vector<vector<ll>> dist(n, vector<ll>(m, INF));
    vector<vector<int>> prev(n, vector<int>(m, -1));
    dist[start.y - 1][start.x - 1] = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    set<pair<ll, pair<int, int>>> st;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            st.insert({dist[y][x], {x, y}});
        }
    }

    for (int i = 0; i < n * m; i++) {
        int2 near = int2(st.begin()->second.first, st.begin()->second.second);
        st.erase(st.begin());


        /*int2 near = int2(-1, -1);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (visited[y][x] == 0 && (near.x == -1 || dist[y][x] < dist[near.y][near.x])) {
                    near = int2(x, y);
                }
            }
        }*/

        visited[near.y][near.x] = 1;

        if (near.x > 0 && map[near.y][near.x - 1] != '#' && 
            dist[near.y][near.x - 1] > dist[near.y][near.x] + 
            ((map[near.y][near.x - 1] == '.')?1:2)) {
            st.erase({dist[near.y][near.x - 1], {near.x - 1, near.y}});
            dist[near.y][near.x - 1] = dist[near.y][near.x] + 
            ((map[near.y][near.x - 1] == '.')?1:2);
            prev[near.y][near.x - 1] = 4;
            st.insert({dist[near.y][near.x - 1], {near.x - 1, near.y}});
        }
        if (near.y > 0 && map[near.y - 1][near.x] != '#' && 
            dist[near.y - 1][near.x] > dist[near.y][near.x] + 
            ((map[near.y - 1][near.x] == '.')?1:2)) {
            st.erase({dist[near.y - 1][near.x], {near.x, near.y - 1}});
            dist[near.y - 1][near.x] = dist[near.y][near.x] + 
            ((map[near.y - 1][near.x] == '.')?1:2);
            prev[near.y - 1][near.x] = 1;
            st.insert({dist[near.y - 1][near.x], {near.x, near.y - 1}});
        }
        if (near.x < m - 1 && map[near.y][near.x + 1] != '#' && 
            dist[near.y][near.x + 1] > dist[near.y][near.x] + 
            ((map[near.y][near.x + 1] == '.')?1:2)) {
            st.erase({dist[near.y][near.x + 1], {near.x + 1, near.y}});
            dist[near.y][near.x + 1] = dist[near.y][near.x] + 
            ((map[near.y][near.x + 1] == '.')?1:2);
            prev[near.y][near.x + 1] = 2;
            st.insert({dist[near.y][near.x + 1], {near.x + 1, near.y}});
        }
        if (near.y < n - 1 && map[near.y + 1][near.x] != '#' && 
            dist[near.y + 1][near.x] > dist[near.y][near.x] + 
            ((map[near.y + 1][near.x] == '.')?1:2)) {
            st.erase({dist[near.y + 1][near.x], {near.x, near.y + 1}});
            dist[near.y + 1][near.x] = dist[near.y][near.x] + 
            ((map[near.y + 1][near.x] == '.')?1:2);
            prev[near.y + 1][near.x] = 3;
            st.insert({dist[near.y + 1][near.x], {near.x, near.y + 1}});
        }
    }

    /*for (auto &x : prev) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/
    if (dist[end.y - 1][end.x - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[end.y - 1][end.x - 1] << endl;
    vector<char> ans = {};
    int2 pos = end;
    pos.x--;
    pos.y--;
    while (prev[pos.y][pos.x] != -1) {
        // cout << pos.y << " " << pos.x << endl;
        if (prev[pos.y][pos.x] == 1) {
            pos.y++;
            ans.push_back('N');
        } else if (prev[pos.y][pos.x] == 2) {
            pos.x--;
            ans.push_back('E');
        } else if (prev[pos.y][pos.x] == 3) {
            pos.y--;
            ans.push_back('S');
        } else if (prev[pos.y][pos.x] == 4) {
            pos.x++;
            ans.push_back('W');
        }
        // break;
        // cout << pos.y << " " << pos.x << endl;
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x;
    }
    cout << endl;
    return 0;
}