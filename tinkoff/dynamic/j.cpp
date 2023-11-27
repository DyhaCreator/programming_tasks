#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int >> map = vector<vector<int >> (n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    vector<int>gist = vector<int>(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            gist[j] += map[i][j];
        }
        for (auto x : gist)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}