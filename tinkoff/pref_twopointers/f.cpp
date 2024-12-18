#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<ll >> >vec = vector<vector<vector<ll >> >(k + 1, vector<vector<ll >> (m + 1, vector<ll>(n + 1)));
    for (int i = 1; i < k + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            for (int l = 1; l < n + 1; l++) {
                ll x;
                cin >> x;
                vec[i][j][l] = vec[i - 1][j][l] + vec[i][j - 1][l] + vec[i][j][l - 1] 
                - vec[i - 1][j - 1][l] - vec[i - 1][j][l - 1] - vec[i][j - 1][l - 1] 
                + vec[i - 1][j - 1][l - 1] + x;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int lx, ly, lz, rx, ry, rz;
        cin >> lx >> ly >> lz >> rx >> ry >> rz;
        ll sum = vec[rx][ry][rz] 
            - vec[lx - 1][ry][rz] - vec[rx][ly - 1][rz] - vec[rx][ry][lz - 1]
            + vec[rx][ly - 1][lz - 1] + vec[lx - 1][ry][lz - 1] + vec[lx - 1][ly - 1][rz]
            - vec[lx - 1][ly - 1][lz - 1];
        cout << sum << " ";
    }
    return 0;
}

//3 2 3 2 -4 3 0 0 -1 -1 5 4 9 0 3 0 -5 1 0 3 -9

/*

3 2 3
2 -4 3 0 0 -1      
-1 5 4 9 0 3  
0 -5 1 0 3 -9

*/