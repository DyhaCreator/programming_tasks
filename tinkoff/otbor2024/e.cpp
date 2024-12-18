#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int w, h;
    cin >> w >> h;
    vector<string> map(w);
    string ch;
    getline(cin, ch);
    for (auto &x : map)
        getline(cin, x);
    vector<vector<int>> len(w, vector<int> (h));
    vector<int> len_m(h, -1);
    for (int y = w - 1; y >= 0; y--) {
        for (int x = 0; x < h; x++) {
            if (map[y][x] == '#') {
                len[y][x] = 0;
            } else {
                len[y][x] = len[y + 1][x] + 1;
            }
            if (map[y][x] == 'M') {
                len_m[x] = max(y, len_m[x]);
            }
        }
    }
    /*for (auto &x : len) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    for (auto &x : len_m)
        cout << x << " ";
    cout << endl;*/
    int max_len = INF;
    for (int i = 0; i < h; i++) {
        if (len_m[i] != -1) max_len = min(max_len, len[len_m[i]][i]);
    }
    // cout << max_len << endl;
    for (int y = w - 1; y >= 0; y--) {
        for (int x = 0; x < h; x++) {
            if (map[y][x] == 'M') {
                // cout << y << " " << x << endl;
                map[y][x] = '.';
                map[y + max_len - 1][x] = 'M';
                /*for (auto &hhh : map)
                    cout << hhh << endl;*/
            }
        }
    }
    for (auto &x : map)
        cout << x << endl;
    return 0;
}