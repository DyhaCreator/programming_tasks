#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll >> vec = vector<vector<ll >> (n + 1, vector<ll>(m + 1));

    for (int i = 0; i < q; i++) {
        int lx, ly, rx, ry, d;
        cin >> lx >> ly >> rx >> ry >> d;
        vec[lx - 1][ly - 1] += d;
        vec[lx - 1][ry] -= d;
        vec[rx][ly - 1] -= d;
        vec[rx][ry] += d;
    } 
    vector<vector<ll >> pref = vector<vector<ll >> (n + 1, vector<ll>(m + 1, 0));
    pref[0] = vector<ll>(m + 1);
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] + vec[i - 1][j - 1] - pref[i - 1][j - 1];
            cout << pref[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}