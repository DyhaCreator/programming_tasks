#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int w, h, k;
    string enter;
    cin >> w >> h >> k;
    getline(cin, enter);
    vector<string> map(w);
    for (auto &x : map)
        getline(cin, x);
    for (auto &x : map)
        cout << x << endl;
    int n = 0;
    for (int y = 0; y < w; y++) {
        for (int x = 0; x < h; x++) {
            if (map[y][x] == 'H' || map[y][x] == 'R') {
                n++;
            }
        }
    }
    vector<vector<pair<int, int>>> g(n);
    for (int y = 0; y < w; y++) {
        for (int x = 0; x < h; x++) {
            if (map[y][x] == 'H' || map[y][x] == 'R') {
                
            }
        }
    }
    return 0;
}