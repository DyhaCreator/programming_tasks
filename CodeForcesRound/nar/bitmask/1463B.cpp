#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a) {
        int y = 0;
        while (abs((1 << y) - x) > abs((1 << (y + 1)) - x))
            y++;
        cout << min((1 << y), (1 << 29)) << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}