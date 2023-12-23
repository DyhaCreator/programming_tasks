#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<vector<int>>c = vector<vector<int>>(n, vector<int>());
    vector<vector<int>>p = vector<vector<int>>(n, vector<int>());
    int maxK = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        maxK = std::max(k, maxK);
        c[i] = vector<int>(k);
        p[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            int c1, p1;
            cin >> c1 >> p1;
            c[i][j] = c1;
            p[i][j] = p1;
        }
    }
    vector<vector<vector<int>>>dp = vector<vector<vector<int>>>(n, vector<vector<int>>(b + 1, vector<int>(maxK + 1)));
    for (int y = 1; y <= b; y++) {
        for (int x = 1; x <= maxK; x++) {
            for (int z = 0; z < )
        }
    }
    return 0;
}