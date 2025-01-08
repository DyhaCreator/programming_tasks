#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<vector<int>>> l(4, vector<vector<int>>(n, vector<int>(m, 0)));
    l[0] = vector<vector<int>>(n, vector<int>(m, 1));
    l[1] = vector<vector<int>>(n, vector<int>(m, -1));
    l[2] = vector<vector<int>>(n, vector<int>(m, 1));
    l[3] = vector<vector<int>>(n, vector<int>(m, -1));
    for (int y = 0; y < n; y++)
        for (int x = 1; x < m; x++)
            l[0][y][x] = ((a[y][x] == '#')?1:l[0][y][x - 1] - 1);
    for (int y = 0; y < n; y++)
        for (int x = m - 2; x >= 0; x--)
            l[1][y][x] = ((a[y][x] == '#')?-1:l[1][y][x + 1] + 1);
    for (int y = 1; y < n; y++)
        for (int x = 0; x < m; x++)
            l[2][y][x] = ((a[y][x] == '#')?1:l[2][y - 1][x] - 1);
    for (int y = n - 2; y >= 0; y--)
        for (int x = 0; x < m; x++)
            l[3][y][x] = ((a[y][x] == '#')?-1:l[3][y + 1][x] + 1);
    vector<vector<int>> d(n, vector<int>(m, INF));
    set<pair<int, pair<int, int>>> st;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (a[y][x] == 'S') d[y][x] = 0;
    for (int y = 1; y < n - 1; y++)
        for (int x = 1; x < m - 1; x++)
            if (a[y][x] != '#') st.insert({d[y][x], {y, x}});
    while (st.size()) {
        int y = (*st.begin()).S.F;
        int x = (*st.begin()).S.S;
        st.erase(*st.begin());
        if (a[y - 1][x] != '#' && d[y - 1][x] > d[y][x] + 1) {
            st.erase({d[y - 1][x], {y - 1, x}});
            d[y - 1][x] = d[y][x] + 1;
            st.insert({d[y - 1][x], {y - 1, x}});
        }
        if (a[y + 1][x] != '#' && d[y + 1][x] > d[y][x] + 1) {
            st.erase({d[y + 1][x], {y + 1, x}});
            d[y + 1][x] = d[y][x] + 1;
            st.insert({d[y + 1][x], {y + 1, x}});
        }
        if (a[y][x - 1] != '#' && d[y][x - 1] > d[y][x] + 1) {
            st.erase({d[y][x - 1], {y, x - 1}});
            d[y][x - 1] = d[y][x] + 1;
            st.insert({d[y][x - 1], {y, x - 1}});
        }
        if (a[y][x + 1] != '#' && d[y][x + 1] > d[y][x] + 1) {
            st.erase({d[y][x + 1], {y, x + 1}});
            d[y][x + 1] = d[y][x] + 1;
            st.insert({d[y][x + 1], {y, x + 1}});
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (d[y][x + l[i][y][x]] > d[y][x] + abs(l[j][y][x]) + 1 && l[i][y][x] != 0) {
                    st.erase({d[y][x + l[i][y][x]], {y, x + l[i][y][x]}});
                    d[y][x + l[i][y][x]] = d[y][x] + abs(l[j][y][x]) + 1;
                    st.insert({d[y][x + l[i][y][x]], {y, x + l[i][y][x]}});
                }
            }
        }
        for (int i = 2; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (d[y + l[i][y][x]][x] > d[y][x] + abs(l[j][y][x]) + 1 && l[i][y][x] != 0) {
                    st.erase({d[y + l[i][y][x]][x], {y + l[i][y][x], x}});
                    d[y + l[i][y][x]][x] = d[y][x] + abs(l[j][y][x]) + 1;
                    st.insert({d[y + l[i][y][x]][x], {y + l[i][y][x], x}});
                }
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] == 'T') {
                cout << d[y][x] << endl;
            }
        }
    }
    return 0;
}