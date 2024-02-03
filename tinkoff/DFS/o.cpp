#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> g;

vector<int> ans = {};

void dfs(int start, vector<int> &visited) {
    visited[start] = 1;
    for (auto &x : g[start]) {
        if (visited[x] == 0) {
            dfs(x, visited);
        }
    }
    ans.push_back(start + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int>sum(n);
    for (auto &x : sum)
        cin >> x;
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int a;
            cin >> a;
            g[i].push_back(a - 1);
        }
    }
    
    vector<int> visited(n);
    dfs(0, visited);

    int k = 0;
    ll timeAns = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            timeAns += sum[i];
            k++;
        }
    }
    cout << timeAns << " " << k << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}