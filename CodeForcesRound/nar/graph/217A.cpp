#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n;

void dfs(vector<pair<int, int>> &a, vector<int> &used, int index, int col) {
    used[index] = col;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0 && (a[index].F == a[i].F || a[index].S == a[i].S)) {
            dfs(a, used, i, col);
        }
    }
}

int main() {
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    vector<int> used(n);
    int col = 1;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(a, used, i, col);
            col++;
        }
    }
    cout << col - 2 << endl;
    return 0;
}