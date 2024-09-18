#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int color = 0;

int dfs(int index, vector<set<int>> &g, vector<int> &visited) {
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (auto &x : a) {
            cin >> x;
            x--;
        }
        for (auto &x : a) {
            for (auto &y : a) {
                if (y != x) g[x].insert(y);
            }
        }
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
    }
    for (auto &x : g) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }

    vector<int> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            color++;
            dfs(i, g, visited);
        }
    }
    return 0;
}