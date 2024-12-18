#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int index = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == index) {
            ans++;
            index++;
            // cout << 0 << " ";
        }
        // cout << x << " ";
        index++;
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}