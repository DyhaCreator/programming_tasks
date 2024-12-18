#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    int ans = 0;
    for (auto &x : a) {
        for (auto &y : x) {
            if ((y - a[0][0]) % d != 0) {
                cout << -1 << endl;
                return 0;
            }
            cout << (y - a[0][0]) / d << endl;
            ans += (y - a[0][0]) / d;
        }
    }
    cout << ans << endl;
    return 0;
}