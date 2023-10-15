#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll >> vec = vector<vector<ll >> (n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        
    }
    return 0;
}