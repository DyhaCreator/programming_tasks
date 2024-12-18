#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int a, b;
        cin >> a >> b;
        cout << max(a, b) << endl;
    }
}

void dfs(int start, vector<int> &visited, vector<vector<int>> &g) {
    visited[start] = 1;
    for (auto &x : g[start]) {
        if (visited[x] == 0) {
            dfs(x, visited, g);
        }
    }
}

void solveB() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
        }
        vector<int> visited(n, 0);
        dfs(0, visited, g);
        
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(NULL);
    solveB();
    return 0;
}