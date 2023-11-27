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
            cin >> map[x][y];
        }
    }
    
    return 0;
}