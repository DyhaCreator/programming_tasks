#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int s = n;
    int ans = INF;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < 16; i++) {
        int save = n + i;
        int count = 0;
        while (save % 2 == 0) {
            save /= 2;
            count++;
        }
        ans = min(ans, 15 - count + i);
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
    return 0;
}