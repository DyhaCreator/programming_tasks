#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int f = 0;
vector<int> p(26, -1);

void dfs(vector<vector<int>> &g, vector<int> &used, int index) {
    used[index] = 1;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, x);
        } else if (used[x] == 1) {
            f = 1;
        }
    }
    used[index] = 2;
}

void dfs2(vector<vector<int>> &g, vector<int> &used, int index, int len) {
    used[index] = len;
    for (auto &x : g[index]) {
        if (used[x] < len + 1) {
            dfs2(g, used, x, len + 1);
        }
    }
}

bool comp(const char &a, const char &b) {
    if (p[a - 'a'] == p[b - 'a']) {
        return a < b;
    }
    return p[a - 'a'] < p[b - 'a'];
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> g(26);
    vector<vector<int>> g2(26);
    for (int i = 1; i < n; i++) {
        int index = 0;
        while (index < min(a[i - 1].size(), a[i].size()) && a[i - 1][index] == a[i][index])
            index++;
        if (index < min(a[i - 1].size(), a[i].size())) {
            g[a[i][index] - 'a'].push_back(a[i - 1][index] - 'a');
            g2[a[i - 1][index] - 'a'].push_back(a[i][index] - 'a');
        } else {
            if (a[i - 1].size() > a[i].size()) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    /*for (int i = 0; i < 26; i++) {
        cout << char(i + 'a') << ": ";
        for (auto &x : g[i])
            cout << char(x + 'a') << " ";
        cout << endl;
    }*/
    vector<int> used(26);
    for (int i = 0; i < 26; i++) {
        if (used[i] == 0) {
            f = 0;
            dfs(g, used, i);
            if (f) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (p[i] == -1) {
            dfs2(g2, p, i, 0);
        }
    }
    string al = "abcdefghijklmnopqrstuvwxyz";
    sort(al.begin(), al.end(), comp);
    cout << al << endl;
    return 0;
}