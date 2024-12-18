#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int y = 1;
    while (y < n)
        y = y << 1;
    y--;
    y = y >> 1;
    int saveY = y;
    // cout << y << endl;
    int index = 0;
    while (y >= 0) {
        a[index] = y;
        y--;
        index++;
    }
    y = saveY + 1;
    while (y < n) {
        a[index] = y;
        y++;
        index++;
    }
    for (auto &x : a)
        cout << x << " ";
    cout << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}