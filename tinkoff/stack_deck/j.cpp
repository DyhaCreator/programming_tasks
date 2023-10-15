#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int >> vec = vector<vector<int >> (n);
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            ll c, x;
            cin >> c >> x;
            vec[c - 1].push_back(x);
        } else if (a == 2) {
            ll c;
            cin >> c;
            cout << vec[c - 1].back() << endl;
            vec[c - 1].erase(vec[c - 1].begin() + vec[c - 1].size() - 1);
        } else if (a == 3) {
            ll x, y;
            cin >> x >> y;
            cout << vec[x - 1][y - 1] << endl;
        }
    }
    return 0;
}