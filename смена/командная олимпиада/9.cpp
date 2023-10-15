#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<bool> used;
vector<int> d;
int s, f;

void dfs(int v, vector<vector<int>> gr) {
    used[v] = true;
    //cout << v + 1 << " ";
    for (auto u : gr[v]) {
        cout << v + 1 << ":" << u + 1 << " ";
        if (!used[u] && d[u] < d[v] + 1 && u != f - 1) {
            // cout << "p" << d[u];
            // cout << " " << d[u] << " " << d[v] << " " << u + 1 << " " << v + 1 << "\n";
            dfs(u, gr);
            d[u] = d[v] + 1;
            cout << d[u] << " " << u << "\n";
        }
    }
}

int main(){
    
    int n, m;
    cin >> n >> m >> s >> f;
    vector<vector<int>> gr(n);
    for ( int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    used.resize(n, false);
    d.resize(n, 0);
    dfs(s - 1, gr);
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << d[f - 1];
    return 0;
}