#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>>img = vector<vector<char>>(n, vector<char>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> img[y][x];
        }
    }
    for (int y = 0; y < n * k; y++) {
        for (int x = 0; x < m * k; x++) {
            cout << img[y / k][x / k];
        } 
        cout << "\n";
    }
    return 0;
}